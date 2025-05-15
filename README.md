# redcombine
Simple CLI tool for combining three textures into one by red channel

Useful for PBR renderers that wish to combine Metallic, Roughness and Ambient Occlusion into a single texture

## Usage
```
redcombine {red} {green} {blue} {output}
```
Where `{red}` is the image that will fill the red channel of `{output}`, similarly for `{green}` and `{blue}`. Note that this tool only reads the red channel of input images.

## Building
`redcombine` uses the `meson` build system:
```
meson setup builddir
meson compile -C builddir
```