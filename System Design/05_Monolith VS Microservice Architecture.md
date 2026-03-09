# Microservice Architecture: Splitting the Giant Pizza Shop

We started with one chef in one shop. As things got bigger, we added more shops and more servers. But even then, there's a limit to how much one "giant shop" can do if it tries to handle everything at once.

## Monolith vs. Microservice

Think of a **Monolith** as one big pizza shop where everyone does everything. The person taking the order is also the one tossing the dough, chopping the veggies, and running the delivery bike. It’s easy to set up at first, but when the shop gets crowded, everyone is bumping into each other. If the delivery bike breaks, the whole shop stops because that same person was also the main chef.

- In technical terms, a monolith is a single, large machine that contains all the business logic of an application. It is deployed as a single unit and communicates with other services through APIs.
- It is scalable horizontally. There may be multiple monoliths running in parallel.

A **Microservice Architecture** is like having specialized shops. You have one shop that _only_ makes the dough, another that _only_ handles the toppings, and a separate delivery center. They talk to each other through the phone (or **APIs**), but they are independent.

- In technical terms, a microservice is a small, independent service that is responsible for a specific business capability. It is deployed as a separate unit and communicates with other services like tiny databases through APIs.
- The client may not be talking to the microservices directly. There may be a gateway that talks to the microservices on behalf of the client.

![Monolith vs Microservice](./assets/images/Monolithic%20VS%20Microservice.png)

<!-- Credits: https://medium.com/startlovingyourself/microservices-vs-monolithic-architecture-c8df91f16bb4 -->

### Pros & Cons: Monolith

**The Good Parts:**

- **Scaling is actually simple:** You can scale out horizontally by just running multiple copies of the same monolith. For a small team, this is often a huge advantage.
- **Lower Complexity:** You don't have to worry about breaking everything into tiny pieces. Deployment is straightforward since it's all in one box.
- **Less Duplication:** Since everything runs on one machine, you don't end up rewriting or copying the same code for different services.
- **Pure Speed:** Procedure calls are almost instant because there are no network hops. Everything happens within the same memory space.

**The Not-So-Good Parts:**

- **Context Overload:** A new developer has to wade through the _entire_ system to understand how anything works.
- **Deployment Headaches:** Every single code change, no matter how small, requires you to redeploy the whole massive application.
- **The "Domino Effect" (SPF):** If the fridge for the toppings breaks and leaks everywhere in our giant shop, the whole floor is a mess and you can't even take orders. If one part of the server crashes, the whole system goes down.

### Pros & Cons: Microservices

**The Good Parts:**

- **Granular Scaling:** If only one part of your app is blowing up (like selling way more drinks than pizzas), you can scale just that "drinks service" instead of the whole shop. It's much cheaper and more efficient.
- **Team Ownership:** When you have 50 chefs in one kitchen, it's a mess. But if a team of 5 people owns the "Delivery Service," they know exactly how their bikes are running. It's easier to manage large teams because everyone has a clear "domain."
- **Fault Tolerance:** If the "topping service" has a problem, the "dough service" is still fine. You might not have pepperoni today, but you can still sell plain bread. The failure is isolated.
- **Parallel Progress:** Different teams can work on different services with fewer dependencies, making it easier to ship features fast.

**The Not-So-Good Parts:**

- **The "Complexity Tax":** You're not shouting across the kitchen anymore; you're making phone calls (network hops). This takes time, and sometimes the line is busy.
- **Data Headaches:** In a monolith, you have one big list of orders. In microservices, the dough shop has their list and the topping shop has theirs. Keeping them in sync is a major challenge.
- **Hard to Debug:** When an order goes missing, you have to check three different shops to find out where it got lost. You need "Distributed Tracing" to track a request across all services.
- **Design Overhead:** It’s very easy to accidentally break a service into too many (or too few) parts. You need smart architects to decide where to use RPCs and how to handle network latency.

## When to Choose?

If you're a startup with 3 people, **stick with the Monolith**. It's faster and simpler.
You only move to microservices when your team gets so big that you can't all sit in one room, or when your app is so complex that one person can't understand the whole thing anymore.

System design is about picking the right tool for the job. Microservices are a powerful tool, but they aren't a silver bullet.
