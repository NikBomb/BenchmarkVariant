# BenchmarkVariant
benchmark of the variant against Dynamic polymorhism


In this Project two different versions of the Strategy Pattern are tested and benchmarked in terms of speed.

The first one is the "classic" or canonical strategy Pattern. In this setting a Strategy object is passed to a Context Object, via constructor. later the polymorhic behaviour is achieved instantiating a container of Contexts and calling the underlying strategy.
In the Policy pattern instead, the policies are template classes that are known at compilation time. A polymorphic container is built using variants, that as well should be known at compile time. The strategy is called using the Visitor pattern.

When optimizations are switched on the policy pattern is faster than the canonical strategy.
