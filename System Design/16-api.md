# API Design: How to Talk to Code Without Breaking Things

Let's say you wrote an incredibly complex and beautiful piece of code. Now someone else wants to use it. You definitely do not want to hand over your actual source code.

Enter the API, **Application Programming Interface**.

An API is simply a documented way for external consumers to interact with your code. It does not explain _how_ the code works under the hood. It just explains _how to talk to it_ to get a job done. Think of it as a contract. You promise to give the API an input and the API promises to hand back a specific output.

Let's use a WhatsApp group as an example. You want to retrieve a list of admins for a particular group. WhatsApp exposes an API for this called `getAdmins(string groupID)`.

If we are working in a microservice architecture, where does this function go? Naturally it belongs in the **Group Service**. This is the microservice that handles all group related data.

---

## The Big 4 Issues of Designing APIs

Designing an API seems simple. You just write a function and return some JSON, right? Well not quite. Here are the common traps most developers fall into.

### 1. Naming: Say What You Mean

If your function is named `getAdmins`, it should _only_ return admin data. If your response suddenly includes a list of completely unrelated groups those admins happen to belong to, your naming is bad. **Do exactly what it says on the box.**

### 2. Parameter Integrity

Your function actions should strictly depend on its name and parameters. Let's say you want an API that checks if a specific list of people are the admins of a group. Should you just add an array parameter to `getAdmins`? **No!** That changes the entire behavior of the function. Instead you should create a brand new API named `checkAdmins`. Keep things separated.

### 3. The Response Object Trap

There are two extremes here.

**The Bloater (Over-fetching):** Developers stuff the response object with tons of extra information. They hope the caller _might need it_ and it will save them a future API call. This is terrible design. It makes the API confusing and slows everything down. It also makes future development a nightmare since you are now committed to returning all this extra junk.

**The Pragmatic Exception:** Let's say `getAdmins` requires making 4 to 5 expensive database calls. If you are getting millions of hits a second, you might optimize this by adding optional parameters to skip certain expensive lookups. It is a trade off but sometimes performance wins over strict cleanliness.

### 4. Defining Errors Properly

You do not need to baby proof everything. For example if your API expects an `int groupID`, the framework usually handles the error if someone passes the word _apple_. You do not need to manually write code to check if it is an integer.

However you should **not** take zero responsibility! If someone looks up a `groupID` that was deleted, do not just throw a generic `404 Not Found` error. `GroupDoesNotExist` or `GroupIsDeleted` are expected business domain errors. Your API should explicitly define and return them. Think about the common expectations and the responsibilities your API has.

---

## HTTP Requests: The Where and the How

If we actually want to trigger this API over the web, we use HTTP. It looks something like this.

`POST www.wpapi.com/chat_messaging/v1/getAdmins`

Let's break that down.

- `www.wpapi.com` is the address of the site.
- `chat_messaging` is the specific service or module we want.
- `v1` is for **API Versioning**. Always version your APIs so you can upgrade them later without breaking older apps.
- `getAdmins` is the actual function we are calling.

Since this is a `POST` request, the client sends a payload or JSON body securely.

```json
{
  "groupID": 123
}
```

And the server responds.

```json
{
  "admins": [{ "id": 123, "name": "John Doe" }]
}
```

Wait, couldn't we do this as a `GET` request? Absolutely! Instead of a payload body, a `GET` request just throws the parameter directly into the URL like this.
`GET www.wpapi.com/chat_messaging/v1/getAdmins?groupID=123`

---

## The Golden Rule: NO SIDE EFFECTS

An API should do exactly what it says and absolutely nothing else.

Let's say you have an API called `setAdmins(List<Admin> admins, int groupID)`
What if the user isn't in the group yet? A clever developer might code the API to automatically add them to the group and make them an admin.
What if the group doesn't even exist? The API might create the group and add the admins.

**Stop right there!** This API is now doing three different jobs. That is a massive side effect.
_Analogy time. If you ask your brother to take out the trash and he throws the entire dustbin away, that is a side effect._

**Atomicity Issues:** If a client expects `setAdmins` to gracefully handle creating a missing group under the hood, imagine what happens if another client hits the server and changes the group members a millisecond later. It would be chaos.

**The Fix:** Give the client a `404 Group Not Found` error. Force the client to explicitly call `createGroup` first and _then_ call `setAdmins`. Keep APIs dumb, predictable and single purpose.

---

## Handling Gigantic Data

What happens if you have an API like `getMembers` and the group has 200,000 people in it? You cannot send all that profile data across the internet at once.

You solve this in one of two ways.

1. **Pagination:** The Client is in charge. The client says to give me the first 10 members. Then it asks for members 11 to 20 and so on in consecutive calls.
2. **Fragmentation or Streaming:** The Server is in charge. The server says here is the first 10KB of data. Then it says wait here comes another 10KB. Then it says okay I am done. It streams the chunks over a TCP connection using markers to say whether more data is coming or not.

---

## Consistency vs Survival

Imagine you call `getAdmins` and it returns 2 admins. But literally one millisecond before your result arrived, a third admin was added. Your data is technically inconsistent.

But the real question in System Design is if you _actually_ care.

If you are loading comments on a viral YouTube video, do you really care if you missed a comment that was posted 3 seconds ago? Probably not. Strict and absolute consistency is incredibly slow and expensive for normal systems.

**Service Degradation:**
If your database is getting crushed with millions of requests during a sudden spike, you can implement **Service Degradation**. Instead of returning the full user profile which requires loading the profile picture and bio and recent posts, the server just returns the username and ID.
You gracefully drop the heavy and unwanted things to keep the server alive. Giving essential information quickly is infinitely better than completely crashing the system!
