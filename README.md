# Union Find

C++ implementation of the UnionFind algorithm.
Thoroughly hacking on this.

## Dockerfile

I'm building the user into the image.
If building the image manually, specify the user from the command line:
```
$ docker build -t <tag> --build-arg user=<username> .
```
I'm specifying the username in docker-compose and am ok with the default UID.

Run with
```
$ docker-compose up --build -d
```

Attach and execute a command with:
```
$ docker exec -t <container_name> <command>
```


### Alternate

Could export the environment variable UID so that docker-compose can pick it up.
If I do this then I might be able to get away with a home-less user.

# Links

[Boost and CMake](https://cmake.org/cmake/help/v3.7/module/FindBoost.html)


### Test logging

Boost supports several useful runtime options:
```
-p  --show-progress
-o  --output_format     HRF (default)
                        XML
-r  --report_level      confirm (default)
                        no
                        short
                        detailed
--detect_memory_leaks   Visual Studio debug mode only?
--list_content
-l  --log_level         all
                        test_suite
                        ...
--log_sink              [Broken in Boost 1.6.2](https://svn.boost.org/trac10/ticket/12507)
                        Use --logger instead.
```

`--logger=HRF,test_suite,benchmark_union_find.txt`
CTest suppresses logfile generation.
logger doesn't catch cpu timer's output.

For now, run from the command line and use
`--log_leve=test_suite`
