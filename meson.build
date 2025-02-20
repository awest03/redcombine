project('redcombine', 'c', version: '1.0.0')

# Source Files
redcombine_src = files(
    'src/main.c',
)

executable(
    'redcombine',
    redcombine_src,
    install: true,
    dependencies: [
        meson.get_compiler('c').find_library('m', required: false)
    ]
)