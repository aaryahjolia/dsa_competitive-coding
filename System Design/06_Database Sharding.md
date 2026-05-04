# Database Sharding: Slicing the Data Pizza

Imagine you have a giant pizza. It's too big for one person to eat, and it's too big for one box to hold. So, what do you do? You slice it up and give different pieces to different friends.

In the database world, we call this **Partitioning**. We divide the data into smaller, manageable chunks so that no single server has to carry the entire load.

### Horizontal vs. Vertical Partitioning

Before we dive into sharding, it's important to know there are two ways to slice this pizza:

1.  **Vertical Partitioning:** This is like separating the crust, the cheese, and the toppings into different boxes. You take specific **columns** (attributes) of your data and move them to different servers.
2.  **Horizontal Partitioning (Sharding):** This is what we usually mean when we talk about sharding. You take the same "rows" of data and distribute them across multiple servers based on a **Shard Key**.

### How Sharding Works

Let's say we have 8 database servers ($S_0$ to $S_7$) and we're using `user_id` as our shard key:

- Server $S_0$ handles `user_id` 0 to 100.
- Server $S_1$ handles `user_id` 101 to 200.
- ...and so on.

By breaking the data into these ranges, we can serve a massive amount of requests by letting each server handle its own "slice" of the user base.

> [IMPORTANT]
> These are **database servers**, not your typical stateless application servers. While an app server can be easily swapped out, a database server holds the "truth" of your data. It can't afford any "hiccups."

### The Golden Rules: Consistency & Availability

In system design, we often talk about the trade-off between **Consistency** (everyone sees the same data at the same time) and **Availability** (the system is always up).

When it comes to databases:

- **Consistency is King:** In most data-heavy applications, it's better for a request to wait a millisecond than to see "garbage" or outdated data.
- **Availability is Critical:** Obviously, we don't want the database to crash, but we often prioritize data integrity over 100% uptime if a conflict occurs.

### Smart Sharding

You can shard your database on any meaningful data. For example, in an app like **Tinder**, you might shard by **Location**. This way, when you query for people near you, the database only has to look at one specific shard instead of searching the entire world.

To make it even faster, you can create **Indexes** on each shard. If you're looking for someone in "NY" between ages "20-25", the system goes to the "NY" shard and then uses an index on the "Age" column to find the result instantly.

---

## The Catch: Sharding Problems

Sharding sounds great, but it comes with some serious headaches:

### 1. The Join Problem

If you need to join data that lives on two different shards (e.g., a "Users" shard and an "Orders" shard), you have to fetch data from both over the network and join them yourself. This is **expensive** and slow.

### 2. The Scaling Bottleneck (Fixed Shards)

Normally, it's hard to add or remove shards once they're set up. If you start with 8 shards and suddenly need 9, you have to move _everything_ around.

- **Solution A: Consistent Hashing.** This is a clever math trick that minimizes data movement when servers are added/removed.
- **Solution B: Hierarchical Sharding.** If a shard gets too full, you dynamically break that "slice" into even smaller "mini-slices." A manager tracks which request goes to which mini-slice, making the system much more flexible.

---

## Database Replication (Master-Slave Architecture)

Database replication is used to keep copies of your data across multiple servers, usually through a **master/slave** relationship. The original is called the master, and the copies are called slaves.

The split is pretty straightforward: the **master** handles all write operations (inserts, updates, deletes), while the **slaves** handle read operations by staying in sync with the master. Since most applications read data far more often than they write it, you'll typically see more slave databases than master ones in a real system.

![Database Master-Slave Architecture](./assets/images/Database%20Master-Slave%20Architecture.png)

<!-- Credits: Alex Xu - System Design Interview -->

### Why Bother Replicating?

- **Better performance:** Writes go to the master, reads spread across slaves. More queries run in parallel, and the whole system feels faster.
- **Reliability:** If a server gets wiped out (hardware failure, natural disaster, whatever), your data still lives on the other replicas. No data loss.
- **High availability:** If one database goes offline, the others can serve requests. The system keeps running even during failures.

### What Happens When Something Goes Down?

- **A slave goes offline:** If there's only one slave and it goes down, reads temporarily fall back to the master until a replacement slave is spun up. If there are multiple slaves, reads just get redirected to the remaining healthy ones.
- **The master goes offline:** One of the slaves gets promoted to become the new master. All writes now go there. This sounds simple, but in practice it can get messy. The promoted slave might not have the very latest data, so recovery scripts may need to run to fill in the gaps. More advanced setups like multi-master or circular replication exist but are significantly more complex.

## Wrap Up

Conceptually, sharding is easy: break data into pieces and spread them out. In practice, it’s one of the hardest things to get right because maintaining **Consistency** across multiple machines is a nightmare.

**Pro Tip:** If you're just starting out, try simpler concepts like **Indexing** or using a **NoSQL** database before jumping into full-scale sharding.
