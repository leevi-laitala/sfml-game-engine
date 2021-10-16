project('sfml-game-engine', 'cpp', default_options: ['cpp_std=c++20'])

sfml2_deps = [
  dependency('sfml-graphics'),
  dependency('sfml-system'),
  dependency('sfml-window'),
  dependency('sfml-audio')]

executable(
  'app',
  'main.cpp',
  'src/sound-manager.cpp',
  'src/engine.cpp',
  'src/scene.cpp',
  'src/element.cpp',
  'src/balloon.cpp',
  'src/button.cpp',
  dependencies : sfml2_deps)
