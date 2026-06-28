# Caching: Reducing the Wait Time

Imagine an Instagram user requests their feed. Here's a typical breakdown of that request:

1. **User $\rightarrow$ Server:** 100ms
2. **Server $\rightarrow$ Database:** 10ms
3. **Database $\rightarrow$ Server (Result):** 10ms
4. **Server $\rightarrow$ User (Response):** 100ms
   **Total Time:** $100 + 10 + 10 + 100 = 220ms$.

How can we make this faster? Caching is the answer.

### The Big Idea: Storage over Latency

A cache is a temporary, high-speed storage layer that holds the results of expensive operations or frequently accessed data. Instead of hammering the database repeatedly for every web page load, the server checks the cache first.

- If we query a local cache, that 10ms trip to the DB might drop to **1ms**.
- **New Total Time:** $100 + 1 + 1 + 100 = 202ms$ (about 10% faster).

We can even cache on the **client side**. If the user puts their phone down and comes back a minute later, we can show them the data we already saved locally. This is lightning fast (virtually 0ms extra latency).

#### The Cache Tier & Read-Through Strategy

By utilizing a dedicated **Cache Tier**, you significantly improve application performance, reduce database workloads, and allow the cache to scale independently of the database. Most cache servers are also easy to interact with via common programming language APIs.

Following code snippet shows typical memcached APIs:

```javascript
SECONDS = 1;
cache.set("myKey", "any random value", 3600 * SECONDS);
cache.get("myKey");
```

A very common approach is the **Read-through strategy**:

1. The server receives a request and checks the cache.
2. If the data is there (**cache hit**), it returns it immediately.
3. If not (**cache miss**), the server queries the database, saves the result in the cache for next time, and returns the response.

> [NOTE]
> Why not put the _entire_ database in the cache?
> Cache memory is expensive. It's great for GBs of data, but for TBs or PBs, it's just not practical. Instead, we keep a "chunk" of the most frequently used data in the cache to get the best out of our spendings.

---

## Considerations for Using a Cache

When introducing a cache system, keep these key points in mind:

### 1. When to Use It

Caches shine in **read-heavy, write-infrequent** scenarios. Consider using cache when data is read frequently but modified infrequently. Since cached data is stored in **volatile memory**, a cache server is not ideal for persisting data. For instance, if a cache server restarts, all the data in memory is lost. Thus, important data should be saved in persistent data stores.

### 2. Consistency & Expiration

When data in the database changes, the cache becomes "stale". Keeping the two in sync is known as maintaining **Consistency**, which can be challenging in large, multi-region systems (like Facebook's Memcache setup).

- **Expiration Policy:** It is a good practice to implement an expiration policy. Once cached data is expired, it is removed from the cache. Without an expiration policy, cached data will be stored in memory permanently.
  - _Too short:_ This will cause the system to reload data from the database too frequently.
  - _Too long:_ The data can become stale.

### 3. Mitigating Failures (SPOF)

A single cache server is a Single Point of Failure (SPOF). If it crashes, your entire system might halt under the sudden database load. To prevent this, use **multiple cache servers** distributed across different data centers and **overprovision memory** (add a percentage buffer) to handle unexpected spikes in usage.

### 4. Eviction: Who gets kicked out?

When the cache is full and new items need to be added, existing items must be removed. This is called **Cache Eviction**. Common policies include:

- **LRU (Least Recently Used):** The most popular method. Kicks out data that hasn't been touched in the longest time.
- **LFU (Least Frequently Used):** Kicks out data that is accessed the least often.
- **FIFO (First In, First Out):** Removes the oldest items first, regardless of access frequency.

#### The Danger: Thrashing

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
