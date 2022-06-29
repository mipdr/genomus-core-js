{
  'targets': [
    {
      'target_name': 'genomus_core_native',
      'sources': [ 
        'src/genomus_core_native.cpp',
        'src/genomus-core/library/decoded_genotype.cpp',
        'src/genomus-core/library/encoded_genotype.cpp',
        'src/genomus-core/library/encoded_phenotype.cpp',
        'src/genomus-core/library/utils.cpp',
        'src/genomus-core/library/parser.cpp',
        'src/genomus-core/library/species.cpp',
        'src/genomus-core/library/features.cpp',
        'src/genomus-core/library/function_library.cpp',
      ],
      'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")"],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'xcode_settings': {
        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
        'CLANG_CXX_LIBRARY': 'libc++',
        'MACOSX_DEPLOYMENT_TARGET': '10.7'
      },
      'msvs_settings': {
        'VCCLCompilerTool': { 'ExceptionHandling': 1 },
      }
    }
  ]
}