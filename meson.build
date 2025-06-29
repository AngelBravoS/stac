project(
    'stac',
    'cpp',
    version : '1.0.0',
    default_options : [
        'buildtype=debug',
        'optimization=0',
        'cpp_std=c++17'
    ],
    meson_version: '>= 0.60.0',
)

# Verificar compilador
cpp = meson.get_compiler('cpp')
compiler_id = cpp.get_id()
compiler_version = cpp.version()

message('Compilador: ' + compiler_id + ', Versión: ' + compiler_version)

# Configuración específica del compilador
common_warning_flags = [
  '-Wpedantic',
  '-Wconversion',
  '-Wshadow',
  '-Wcast-qual',
  '-Wwrite-strings'
]

debug_flags = ['-g3', '-ggdb3', '-DDEBUG']
release_flags = ['-O3']

# Aplicar flags según el compilador y build type
if compiler_id == 'clang'
  message('Configurando para compilador Clang')
  if get_option('buildtype') == 'debug'
    add_project_arguments(common_warning_flags + debug_flags, language : 'cpp')
  else
    add_project_arguments(common_warning_flags + release_flags, language : 'cpp')
  endif
elif compiler_id == 'gcc'
  message('Configurando para compilador GCC')
  if get_option('buildtype') == 'debug'
    add_project_arguments(common_warning_flags + debug_flags, language : 'cpp')
  else
    add_project_arguments(common_warning_flags + release_flags, language : 'cpp')
  endif

elif compiler_id == 'msvc'
  message('Configurando para compilador msvc')
  if get_option('buildtype') == 'debug'
    compile_args += [
      '/MDd', '/RTC1', '/permissive', '/W3', '/Wall',
      '/DDEBUG', '/Od', '/Ob0', '/Zi', '/utf-8', '/MP',
      '/wd4820', '/wd5045', '/wd4668'
    ]
  elif get_option('buildtype') == 'release'
    compile_args += ['/O2', '/W3']
  endif

else
  warning('Compilador no soportado (' + compiler_id + '). No se aplican banderas específicas.')
endif

# Fuentes del proyecto
lista_archivos = [
    'src/main.cpp',
    'src/cli.cpp',
    'src/entrada.cpp',
    'src/salida.cpp',
    'src/textosMenus.cpp',
    'src/vector.cpp',
    'src/row.cpp',
    'src/matriz.cpp',
    'src/funcMatematicasBasicas.cpp',
    'src/calculos1Var.cpp',
    'src/calculos2Var.cpp',
    'src/calculosNVar.cpp',
    'src/calculosAlgebra.cpp',
    'src/combinatoria.cpp',
    'src/distribucionesDiscretas.cpp',
    'src/menuNVar.cpp',
    'src/menuInferencia.cpp',
    'src/menuSinDatos.cpp',
    'src/menuCombinatoria.cpp',
    'src/menuDistribDiscretas.cpp',
    'src/menuSimula.cpp',
    'src/generadoresCongruenciales.cpp',
    'src/menuColExpo.cpp',
    'src/modeloColas.cpp',
    'src/mmi.cpp',
    'src/mmik.cpp',
    'src/mmc.cpp',
    'src/mmInfinit.cpp',
    'src/mgi.cpp',
]

executable('stac',
  lista_archivos,
  include_directories : include_directories('include'),
  install : true
)

# Pruebas automáticas
test('CompiladorCorrecto',
  find_program('echo'),
  args : ['Compilador: ' + compiler_id + ', Versión: ' + compiler_version]
)

