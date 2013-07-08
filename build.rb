#!/usr/bin/env ruby

# update git submodules
puts %x{ git submodule update --init }

# build mruby for tizen
puts %x{ cd vendor/mruby && ./minirake }

# build examples
puts %x{ cd example/service_app/build && native-make }
