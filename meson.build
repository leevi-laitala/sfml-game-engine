project('sfml-game-engine', 'cpp', default_options: ['cpp_std=c++20'])

sfml2_deps = [
  dependency('sfml-graphics'),
  dependency('sfml-system'),
  dependency('sfml-window'),
  dependency('sfml-audio')]

executable(
  'app',
  'main.cpp',
  'demo.cpp',
  'src/balloon.cpp',

  'include/sound-manager.cpp',
  'include/engine.cpp',
  'include/scene.cpp',
  'include/element.cpp',
  'include/button.cpp',
  'include/text.cpp'
  dependencies : sfml2_deps)
