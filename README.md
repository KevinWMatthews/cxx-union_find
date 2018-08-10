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
