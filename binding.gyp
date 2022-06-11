{
  'targets': [
    {
      'target_name': 'genomus_core_native',
      'sources': [ 
        'src/genomus_core_native.cpp',
        'src/genomus-core/library/parameter_mapping.cpp',
        'src/genomus-core/library/features.cpp',
        'src/genomus-core/library/species.cpp',
        'src/genomus-core/library/encoded_phenotype.cpp',
        'src/genomus-core/library/decoded_genotype.cpp',
        'src/genomus-core/common/error_handling/error_handling.cpp'
      ],
      'actions': [
        {
          'action_name': 'precompilation_magic',
          'inputs': ['src/precompilation.py'],
          'outputs': [''],
          'action': ['python3', 'src/precompilation.py'],
        },
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