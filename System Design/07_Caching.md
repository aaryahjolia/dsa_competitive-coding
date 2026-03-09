# Caching: Reducing the Wait Time

Imagine an Instagram user requests their feed. Here's a typical breakdown of that request:

1. **User $\rightarrow$ Server:** 100ms
2. **Server $\rightarrow$ Database:** 10ms
3. **Database $\rightarrow$ Server (Result):** 10ms
4. **Server $\rightarrow$ User (Response):** 100ms
   **Total Time:** $100 + 10 + 10 + 100 = 220ms$.

How can we make this faster? Caching is the answer.

### The Big Idea: Storage over Latency

Caching is all about **reducing repeatable work through storage**. Instead of going to the database every single time, we store the result in a local, super-fast memory.

- If we query a local cache, that 10ms trip to the DB might drop to **1ms**.
- **New Total Time:** $100 + 1 + 1 + 100 = 202ms$ (about 10% faster).

We can even cache on the **client side**. If the user puts their phone down and comes back a minute later, we can show them the data we already saved locally. This is lightning fast (virtually 0ms extra latency).

> [NOTE]
> Why not put the _entire_ database in the cache?
> Cache memory is expensive. It's great for GBs of data, but for TBs or PBs, it's just not practical. Instead, we keep a "chunk" of the most frequently used data in the cache to get the most bang for our buck.

---

## Cache Policies: What stays and what goes?

Since cache memory is limited, we need rules (policies) to manage it.

### 1. Management: How do I handle writes?

When data in the DB changes, the cache is now "stale" (outdated). We have to decide:

- Do we update the cache and DB at the same time?
- Or do we update the cache later? (This leads to **Eventual Consistency**, where the cache might be slightly behind the "truth" for a few seconds/minutes.)

### 2. Eviction: Who gets kicked out?

When the cache is full and something new (like a viral video) needs to come in, we have to delete something else.
Common algorithms include:

- **LRU (Least Recently Used):** Kick out the data that hasn't been touched in the longest time.
- **LFU (Least Frequently Used):** Kick out the data that is accessed the least often.

### The Danger: Thrashing

Poor cache policies can actually hurt performance. This is called **Thrashing**.
Imagine your cache can only hold 3 items, but your requests come in a sequence like $1, 2, 3, 4, 1, 2, 3...$

1. $1, 2, 3$ fill the cache.
2. Request $4$ comes $\rightarrow$ Cache is full $\rightarrow$ LRU kicks out $1$.
3. Request $1$ comes again $\rightarrow$ Cache Miss $\rightarrow$ Load from DB $\rightarrow$ Kicks out $2$.
   You're doing useless work loading and unloading data, which actually _increases_ latency.

---

## Where does the cache live?

Usually, large systems use a combination of these three placements:

1.  **In-Memory Cache (Local):** Lives directly on the individual app servers (like a `Map` in Java/Go). Very fast, but limited to that one server.
2.  **Database Cache:** The database itself caches the results of common queries.
3.  **Global/Distributed Cache:** An independent server (or cluster) dedicated _only_ to caching.
    - **Example:** **Redis**.
    - **Benefits:** It scales independently, can be accessed by all your services, and you can change its logic without redeploying your entire application.

### Conclusion

Caches are lifesavers for performance, but they aren't magic. **Cache Placement** and **Cache Policy** are the two screws you have to turn to get it right. If you're building a large-scale system, a distributed cache like Redis is almost always your best bet.
