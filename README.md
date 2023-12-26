GB Harvest
==========

This is a little project from me to program a simple Game Boy Color game for
myself.

The idea is to walk around as a ghost (because i like ghosts) and repair an old
harvest field to grow crops and sell them to monsters in your basement.

It's not supposed to be a great game, the journey is what counts the most for
me with this project.


Play the game
-------------

You can either download one of the releases or compile the code yourself.
Then use the ROM in your emulator or copy it on your favorite device.

Here are some emulators to choose from if you don't know any:
* https://bgb.bircd.org
* https://mgba.io


Compile from source
-------------------

You need the
[gbdk-2020](https://github.com/gbdk-2020/gbdk-2020/releases) Game Boy
development kit downloaded somewhere on your PC.

Edit the path to your gbdk-2020 installation in the files
`/CMakeLists.txt` and `/Makefile`.

Go into the directory of the `/Makefile` and compile the cartridge with
```shell
make build
```

I only use the `/CMakeLists.txt` to give me code completion for the
gbdk header files in CLion, to compile the game only the `/Makefile` is
needed.


Credits
-------

The tile set I use is from [DeadlyEssence01](https://deadlyessence.itch.io/1-bit-colored-pack)
