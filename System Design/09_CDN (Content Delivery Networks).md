# Content Delivery Networks (CDN)

A **Content Delivery Network (CDN)** is a network of geographically dispersed servers used to deliver static content. CDN servers cache static content like images, videos, CSS, JavaScript files, etc. It makes your website both cheaper to run and faster to access.

### The Latency Problem

Imagine you have a server in **India**, and a user in the **US** wants to load your website:

- The request has to travel half the globe to reach your server.
- The server then sends back a large HTML file, which travels all the way back across the globe.
- **The Result:** High latency and a slow experience for the user. Even a half-second delay can cause a user to lose trust and leave.

![CDN Architecture](./assets/images/CDN.png)

<!-- Image Credits: GeeksforGeeks -->

Moving your server to a central location doesn't solve it; it just makes _everyone_ experience some latency.

### The Solution: Global Caching

A CDN is essentially a distributed system of cache servers (often called **Edge Servers**) placed in different regions around the world. Instead of one central "Mother Server," you have smaller chunks of your data stored locally in each region.

### Why use a CDN?

1.  **Lightning Fast Speed:** Users connect to the server closest to them. Lower distance = lower latency.
2.  **Regulatory Compliance:** Some data can only be shown in certain countries. For example, a movie might have a license for India but not the US. You can store the Indian version in the India cache and not the central global database.
3.  **Cheaper & More Efficient:** Serving static content (videos, images, files) from a CDN is much cheaper than serving it from your main application servers.

### How it Works

A CDN acts like a "Black Box" for static content.

- It's a real server with a file system that the "Mother Server" can manipulate.
- It returns data when you hit its API endpoints.
- You decide what the CDN stores—usually heavy, unchanging data like videos and high-res images.

At a high level: when a user visits a website, the CDN server **closest to the user** will deliver static content. Intuitively, the further users are from CDN servers, the slower the website loads. For example, if CDN servers are in San Francisco, users in Los Angeles will get content faster than users in Europe.

![CDN Usage](./assets/images/CDN%20Usage.png)

<!-- Credits:  https://learn.microsoft.com/en-us/azure/architecture/best-practices/cdn -->

### Features of a Great CDN:

- **Proximity:** Boxes are physically closer to the users.
- **Smart Routing:** It handles regional regulations automatically so your main server doesn't have to.
- **Easy Updates:** Syncing new content from the main server is seamless.

**Example:** **Amazon CloudFront** is a popular choice because it's cheap, reliable, and very easy to integrate.

---

## Considerations of Using a CDN

- **Cost:** CDNs are run by third-party providers, and you are charged for data transfers in and out of the CDN. Caching infrequently used assets provides no significant benefits so you should consider moving them out of the CDN.
- **Setting an appropriate cache expiry:** For time-sensitive content, setting a cache expiry time is important. The cache expiry time should neither be too long nor too short.
  - _Too long:_ The content might no longer be fresh.
  - _Too short:_ It can cause repeat reloading of content from origin servers to the CDN.
- **CDN fallback:** You should consider how your website/application copes with CDN failure. If there is a temporary CDN outage, clients should be able to detect the problem and request resources from the origin.
- **Invalidating files:** You can remove a file from the CDN before it expires by performing one of the following:
  - Invalidate the CDN object using APIs provided by CDN vendors.
  - Use **object versioning** to serve a different version of the object. To version an object, you can add a parameter to the URL, such as a version number. For example, version number 2 is added to the query string: `image.png?v=2`.

The figure below shows a design after a CDN and cache layer are added:

![CDN + Cache Architecture](./assets/images/CDN%20+%20Cache%20Architecture.png)

---

### Conclusion

CDNs are a prerequisite for any global distributed system. They take the load off your main servers and ensure that your users get the fastest experience possible, no matter where they are in the world.
