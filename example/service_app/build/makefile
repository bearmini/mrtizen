
PACKAGE_ID = $(shell cat .package_id)
ARTIFACT=MrtizenExampleService.exe

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
# -include sources.mk
O_SRCS := 
PO_SRCS := 
CPP_SRCS := 
C_UPPER_SRCS := 
C_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
EDC_SRCS := 
ASM_SRCS := 
CXX_SRCS := 
C++_SRCS := 
CC_SRCS := 
MO_FILES := 
OBJS := 
C++_DEPS := 
C_DEPS := 
CC_DEPS := 
EDJ_FILES := 
CPP_DEPS := 
EXECUTABLES := 
C_UPPER_DEPS := 
CXX_DEPS := 

# Every subdirectory with source files must be described here
SUBDIRS := \
src \

# -include src/subdir.mk
# Add inputs and outputs from these tool invocations to the build variables 
CPP_FILES = $(wildcard ../src/*.cpp)
CPP_SRCS += $(CPP_FILES)
OBJS += $(patsubst ../src/%.cpp,./src/%.o,$(CPP_FILES))
CPP_DEPS += $(patsubst ../src/%.cpp,./src/%.d,$(CPP_FILES))

DFLAGS = -D_DEBUG -D_APP_LOG
IFLAGS = -I"$(PROJPATH)/inc"
IFLAGS+= -I"$(PROJPATH)/../../vendor/mruby/include"
IFLAGS+= -I"$(PROJPATH)/../../vendor/mrubybind"
IFLAGS+= -I"$(SDKPATH)/library"
IFLAGS+= -I"$(ROOTSTRAP)/usr/include"
IFLAGS+= -I"$(ROOTSTRAP)/usr/include/osp"
IFLAGS+= -I"$(ROOTSTRAP)/usr/include/libxml2"

# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: C++ Compiler'
	$(CC) $(DFLAGS) $(IFLAGS) -O0 -g3 -Wall -c -fmessage-length=0 $(TC_COMPILER_MISC) -fPIE --sysroot="$(ROOTSTRAP)" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


USER_OBJS :=
LIBS :=

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs


# All Target
all: output-directory $(ARTIFACT) secondary-outputs

output-directory:
	mkdir -p src

LIBS = -lmruby -lpthread -losp-uifw -losp-appfw -losp-image -losp-json -losp-ime -losp-net -lpthread -losp-content -losp-locations -losp-telephony -losp-uix -losp-media -losp-messaging -losp-web -losp-social -losp-wifi -losp-bluetooth -losp-nfc -losp-face -losp-speech-tts -losp-shell -losp-shell-core -losp-speech-stt -losp-vision -lxml2

LFLAGS = -L"$(PROJPATH)/lib"
LFLAGS+= -L"$(PROJPATH)/../../vendor/mruby/build/tizen-arm/lib/"
LFLAGS+= -L"$(ROOTSTRAP)/usr/lib"
LFLAGS+= -L"$(ROOTSTRAP)/usr/lib/osp"

$(ARTIFACT): $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: C++ Linker'
	$(CC) -o"$(ARTIFACT)" $(OBJS) $(USER_OBJS) $(LIBS) $(LFLAGS) $(TC_LINKER_MISC) -pie -Xlinker -rpath="/opt/usr/apps/${PACKAGE_ID}/lib" -Xlinker -rpath="/home/developer/sdk_tools/lib" --sysroot="$(ROOTSTRAP)" -Wl,-Map,$@.map

# Other Targets
clean:
	-$(RM) $(MO_FILES)$(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(EDJ_FILES)$(CPP_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS) $(ARTIFACT)
	-@echo ' '

secondary-outputs: $(MO_FILES) $(EDJ_FILES)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
