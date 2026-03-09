# Load Balancing: Keeping the Peace Between Servers

So we already know that a server is basically just a computer that takes a request and sends back a response. But eventually, you're going to have too many users for just one computer to handle. You reach for scalability and add more servers.

Now you have a new problem. If you have 10 servers, how do you decide which request goes to which server? You don't want one server doing all the work while the other 9 are just chilling. Spreading this work out evenly is what we call **Load Balancing**.

## The Hashing Trick

How do we actually balance the load? A basic way is to use a bit of math. Every request usually comes with a unique ID (like a username or a session ID). Let's call it a request ID.

To decide where it goes, we use a hash function. It looks something like this:
**H(r1) = M1 % N**

Here's the breakdown:

- **r1** is the request ID.
- **M1** is a random number generated from that ID by our hash function.
- **N** is the number of servers we have.

Basically, we take that random number, divide it by the number of servers, and look at the remainder. That remainder tells us exactly which server to pick.

For example, if we have 4 servers:

1. If our hash function gives us 10 for a request, then **10 % 4 = 2**. We send it to server number 3 (since we start counting from 0).
2. If another request gives us 15, then **15 % 4 = 3**. That one goes to server number 4.

Since these hashes are pretty much random, the load gets spread out evenly. If you have 100 requests and 4 servers, each server ends up with about 25 requests. We call that **1/N load factor**.

## The "Adding a Server" Disaster

This looks perfect on paper, but watch what happens when we add just one more server to help out. Now we have 5 servers (**N = 5**).

Let's look at our requests again:

1. For the first one (hash = 10), it's now **10 % 5 = 0**. Suddenly, it goes to server 1 instead of server 3.
2. For the second one (hash = 15), it's **15 % 5 = 0**. This one also moves to server 1 instead of server 4.

Notice the problem? Adding one single server made almost every request fly to a completely different place than before.

## Why Should we Care?

In the real world, we often want the same user to hit the same server every time. If I'm "user123," and I always go to server 3, that server can keep a **local cache** of my profile or my settings. It makes everything way faster because the server doesn't have to go look me up in the database every single time.

But if we add a new server and my request suddenly jumps to server 1, that local cache is now useless. Server 1 doesn't know who I am and has to do all the work from scratch.

## Finding a Better Way

Standard hashing works fine if your server count never changes, but in a real system, servers go down or you add new ones during busy hours. We need a way to add or remove servers without causing a massive "re-shuffle" of all our requests.

This is where a more advanced concept called **Consistent Hashing** comes into play. It solves exactly this problem by making sure only a tiny fraction of requests move when the number of servers changes.

### Consistent Hashing: The Smart Way

In consistent hashing, we still have our request IDs and we still hash them. But instead of a simple linear array, we imagine the hash values are mapped onto a circle or a **cyclic array**. Think of it as a clock face where the numbers go from 0 up to M-1 and then loop back to 0.

Now, instead of just hashing the requests, we also hash the **server IDs** themselves and place them on this same circle. We use the same hash function (or a different one, it doesn't really matter) and modulo the result by M.

![Consistent Hashing Ring](./assets/images/Hashing%20-%20Final.png)

As you can see in the image, both the servers and the requests are scattered around the circle. The rule is simple: every request travels clockwise around the circle until it hits the first server it finds. That’s the server that handles the request.

This is a game changer. If you add a new server (let's say we add **s4**), it only "steals" a few requests from the server that was right after it on the ring. In the image example, if s4 is added, a request like **key0** might now hit s4 instead of traveling all the way to s0. But every other request on every other server remains exactly where it was. The impact is minimal.

Theoretically, if everything is spread out well, we should see that nice **1/N load factor** where every server does its fair share.

### Handling "Hot Spots" with Virtual Servers

There is one catch. If you only have a few servers, they might end up in a cluster on one side of the circle, leaving one server to handle a massive chunk of the ring. If one server goes down, its neighbor suddenly gets crushed by all that extra work.

To fix this, we use **Virtual Servers**. Instead of placing a server on the ring just once, we hash it multiple times using different hash functions and place it in several spots.

If we have 4 real servers and use 3 hash functions each, we now have **12 virtual servers** evenly spread out across the ring. This balances the load much better. A common rule is to use something like **log(M)** hash functions to make sure no single server gets stuck with too much work.

This concept of load balancing and consistent hashing is what keeps massive distributed systems running smoothly without falling apart every time a machine is added or removed.

Load balancing concepts are used extensively in distributed systems.
