# Low-Level Design Patterns in C++

This repository is a practical reference for **Low-Level Design (LLD)** and
object-oriented design patterns. Each example is intentionally small, focused,
and executable so that the design can be understood before it is applied to a
larger system.

The guide below covers the classic **Gang of Four (GoF)** patterns and several
patterns frequently used in LLD interviews and production systems. The source
code currently included in this repository is marked with **Implemented**.

---

## What is LLD?

Low-Level Design describes the internal structure of a software system:

- classes, interfaces, and responsibilities
- object collaboration and communication
- extensibility and separation of concerns
- lifecycle, state, and dependency management
- error handling, testability, and maintainability

Patterns are reusable design vocabulary, not rules. Apply a pattern only when
it makes the design clearer or easier to change.

## Pattern selection guide

| Design problem | Patterns to consider |
|---|---|
| Create objects without exposing construction details | Factory Method, Abstract Factory, Builder, Prototype |
| Ensure one shared instance | Singleton |
| Adapt an incompatible API | Adapter |
| Add behavior without modifying a class | Decorator |
| Simplify a complex subsystem | Facade |
| Control access to an object | Proxy |
| Notify dependent objects about changes | Observer |
| Select an algorithm at runtime | Strategy |
| Encapsulate a request or operation | Command |
| Change behavior based on an internal state | State |
| Add behavior around an operation | Chain of Responsibility, Template Method |
| Coordinate many objects | Mediator |
| Traverse a collection uniformly | Iterator |
| Represent part-whole structures | Composite |

---

## Creational patterns

Creational patterns control how objects are created and help keep construction
logic separate from business logic.

### Factory Method — Implemented

**Intent:** Define an interface for creating an object while allowing a
subclass or a separate creator to decide which concrete type is instantiated.

**Use when:** The client should depend on an abstraction and object creation
may vary by input, configuration, or subclass.

**Trade-off:** Adds creator types and indirection, but avoids large conditional
constructors and makes new product types easier to add.

### Abstract Factory — Implemented

**Intent:** Create families of related objects without specifying their
concrete classes.

**Use when:** Products must be compatible with one another, such as a matching
set of controls for a theme or a database client family.

**Trade-off:** Adding a new product family is easy; adding a new product kind
requires changes to every factory.

### Builder — Implemented

**Intent:** Construct a complex object step by step while keeping the same
construction process independent of the final representation.

**Use when:** An object has many optional fields, validation rules, or
construction steps.

**Trade-off:** More types and code, but safer construction and readable,
fluent call sites.

### Prototype

**Intent:** Create new objects by copying an existing object.

**Use when:** Initialization is expensive or the object has many possible
configurations.

**Trade-off:** Copying nested objects requires careful deep-copy semantics.

### Singleton — Implemented

**Intent:** Ensure a class has one instance and provide a global access point.

**Use when:** A genuinely process-wide resource must have a single owner.

**Trade-off:** Global state makes testing and dependency management harder.
Prefer dependency injection when a shared instance is not strictly required.

---

## Structural patterns

Structural patterns describe how classes and objects are composed.

### Adapter — Implemented

**Intent:** Convert the interface of an existing class into the interface
expected by its client.

**Use when:** Integrating legacy code, third-party libraries, or incompatible
interfaces.

**Trade-off:** Isolates integration changes, but adds a translation layer.

### Bridge

**Intent:** Separate an abstraction from its implementation so both can vary
independently.

**Use when:** A class has two independent dimensions of change, such as
shape and rendering platform.

**Trade-off:** Reduces subclass combinations at the cost of more abstractions.

### Composite

**Intent:** Compose objects into tree structures and treat individual objects
and compositions uniformly.

**Use when:** Modeling files and directories, UI components, or organization
hierarchies.

**Trade-off:** Uniformity simplifies clients, but not every operation is
equally natural for leaves and composites.

### Decorator — Implemented

**Intent:** Attach additional responsibilities to an object dynamically.

**Use when:** Features should be combined at runtime without creating a
subclass for every combination.

**Trade-off:** Flexible composition can produce many small wrapper objects and
make debugging less direct.

### Facade — Implemented

**Intent:** Provide a simple, stable interface to a complex subsystem.

**Use when:** Clients should not know the subsystem's internal coordination.

**Trade-off:** Reduces coupling, but the facade must not become a god object.

### Flyweight

**Intent:** Share common immutable state between many fine-grained objects to
reduce memory usage.

**Use when:** Large numbers of objects share repeated intrinsic data.

**Trade-off:** Saves memory but introduces lookup and state-separation
complexity.

### Proxy — Implemented

**Intent:** Provide a substitute or placeholder that controls access to
another object.

**Common forms:** Virtual proxy, protection proxy, remote proxy, and caching
proxy.

**Use when:** Access needs lazy loading, authorization, remote communication,
logging, or caching.

**Trade-off:** Adds an extra hop and can hide expensive behavior if the
contract is unclear.

---

## Behavioral patterns

Behavioral patterns describe communication, responsibility, and algorithm
selection between objects.

### Chain of Responsibility

**Intent:** Pass a request through a chain of handlers until one handles it.

**Use when:** Multiple handlers may process a request, such as validation,
logging, authorization, or middleware.

**Trade-off:** Decouples sender and receiver, but handling order must be
documented and tested.

### Command

**Intent:** Encapsulate a request as an object.

**Use when:** Operations need queuing, retrying, logging, undo/redo, or
transaction-like execution.

**Trade-off:** Adds command classes, but makes operations composable.

### Iterator

**Intent:** Traverse a collection without exposing its internal structure.

**Use when:** A collection needs multiple traversal strategies or a stable
iteration interface.

**Trade-off:** Extra abstraction can be unnecessary for simple containers.

### Mediator

**Intent:** Encapsulate how a set of objects interact so they do not depend on
each other directly.

**Use when:** Many-to-many communication is causing tightly coupled classes.

**Trade-off:** Simplifies colleagues, but the mediator can become overly
complex.

### Memento

**Intent:** Capture and restore an object's state without exposing its
implementation.

**Use when:** Implementing undo, checkpoints, drafts, or transaction rollback.

**Trade-off:** State snapshots may consume significant memory.

### Observer — Implemented

**Intent:** Define a one-to-many dependency so observers are notified when a
subject changes.

**Use when:** Subscribers need event-driven updates without the subject knowing
their concrete types.

**Trade-off:** Reduces direct coupling, but notification order, cycles, and
subscriber lifetime need careful handling.

### State

**Intent:** Allow an object to change behavior when its internal state changes.

**Use when:** Large conditional blocks represent distinct lifecycle states.

**Trade-off:** State classes improve isolation but increase the number of types.

### Strategy

**Intent:** Define a family of interchangeable algorithms and select one at
runtime.

**Use when:** A behavior varies independently from the object that uses it.

**Trade-off:** Makes algorithms testable and replaceable, but clients must
choose or receive a strategy.

### Template Method

**Intent:** Define the skeleton of an algorithm while allowing subclasses to
override selected steps.

**Use when:** Workflows share an invariant sequence but differ in individual
steps.

**Trade-off:** Reuse through inheritance can be less flexible than
composition.

### Visitor

**Intent:** Add operations to an object structure without changing the
structure's classes.

**Use when:** The object model is stable but many unrelated operations are
expected.

**Trade-off:** New operations are easy to add; adding a new element type
requires changes to visitors.

---

## Common LLD patterns beyond GoF

These are architectural or concurrency patterns frequently combined with GoF
patterns:

- **Dependency Injection:** Pass dependencies into a class instead of
  constructing them internally.
- **Repository:** Encapsulate persistence and expose a domain-oriented
  collection interface.
- **Service Layer:** Keep application use cases separate from transport and
  persistence concerns.
- **Unit of Work:** Track changes and commit related persistence operations as
  one logical unit.
- **Specification:** Represent business rules as composable predicates.
- **Object Pool:** Reuse expensive, bounded resources such as connections or
  workers.
- **Null Object:** Provide a safe no-op implementation instead of repeated
  null checks.
- **Read-Write Lock:** Allow concurrent reads while serializing writes.
- **Producer-Consumer:** Decouple work production from work processing with a
  queue.
- **Publish-Subscribe:** Route events through a broker so publishers and
  subscribers remain independent.

---

## Repository examples

| Directory | Topics covered |
|---|---|
| [`Adapter Design Pattern`](./Adapter%20Design%20Pattern) | Adapter |
| [`Builder Method`](./Builder%20Method) | Builder and builder variants |
| [`Decorator Pattern`](./Decorator%20Pattern) | Decorator |
| [`Facade Pattern`](./Facade%20Pattern) | Facade |
| [`Factory Design Pattern`](./Factory%20Design%20Pattern) | Simple Factory, Factory Method, Abstract Factory |
| [`Observe Design Pattern`](./Observe%20Design%20Pattern) | Observer |
| [`Proxy Design Pattern`](./Proxy%20Design%20Pattern) | Virtual Proxy |
| [`singleton design pattern`](./singleton%20design%20pattern) | Singleton variants |

---

## Build and run

Requirements:

- A C++17-compatible compiler such as GCC or MSVC
- PowerShell or another terminal on Windows

Compile and run any example from the repository root:

```powershell
g++ -std=c++17 ".\Adapter Design Pattern\adapter.cpp" -o ".\Adapter Design Pattern\adapter.exe"
& ".\Adapter Design Pattern\adapter.exe"
```

Replace the source and output paths with the example you want to run. For
example:

```powershell
g++ -std=c++17 ".\Observe Design Pattern\observe.cpp" -o ".\Observe Design Pattern\observe.exe"
& ".\Observe Design Pattern\observe.exe"
```

Compiled binaries are ignored by Git.

## Recommended learning order

1. Learn interfaces and composition through **Adapter** and **Facade**.
2. Study object creation with **Factory** and **Builder**.
3. Study object composition with **Decorator**, **Composite**, and **Proxy**.
4. Study communication and algorithms with **Observer**, **Strategy**, and
   **Command**.
5. Study lifecycle modeling with **State** and **Template Method**.
6. Apply dependency injection and repository/service patterns in complete LLD
   designs.

## Contributing

Keep examples self-contained, compile with C++17, and place each new pattern
in a clearly named directory. Include a short explanation of the problem the
pattern solves and prefer ownership-safe modern C++ in new examples.
