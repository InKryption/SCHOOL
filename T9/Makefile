# start FUNCTIONS
define All_Files_Inside
$(foreach file,$(wildcard $(1)/*),$(if $(wildcard $(file)/*),$(call All_Files_Inside,$(file)),$(file)))
endef
# end FUNCTIONS

COMPILER:=g++-posix

# Absolute root to project folder
root:=.

BIN:=bin
SRC:=src
BUILD:=Debug
NAME:=login_prog


SRC_FOLDER:=$(root)/$(SRC)# Source folder absolute path
BIN_FOLDER:=$(root)/$(BIN)# Binary folder absolute path


# Linker Flags
LFlags:=\
-LC:\.dev\MinGW-w64\posix\bin -Wl,-Bstatic -latomic -lgomp -lquadmath -lssp -lstdc++ -lwinpthread

# Compiler Flags
CFlags:=\
-I$(SRC_FOLDER) \
-std=gnu++17 \

# Output & Object Output directories
ODIR:=$(BIN_FOLDER)/$(BUILD)
OBJDIR:=$(ODIR)/obj

# List of Source file paths, and a list of matching object files
SOURCE_FILES:=$(filter %.cpp,$(call All_Files_Inside,$(SRC_FOLDER)))
OBJECT_FILES:=$(foreach src,$(SOURCE_FILES),$(OBJDIR)/$(firstword $(subst ., ,$(notdir $(src)))).o)



$(ODIR)/$(NAME).exe: $(OBJECT_FILES)
	@echo ""
	$(COMPILER) $(OBJECT_FILES) -o $(ODIR)/$(NAME).exe $(LFlags)
	@echo ""


# Do this in the foreach, so that every source file in the list created before goes through this process automatically.
define Compile_Source
$(OBJDIR)/$(notdir $(firstword $(subst ., ,$(1)))).o: $(1)
	$(COMPILER) -c $(1) -o $(OBJDIR)/$(notdir $(firstword $(subst ., ,$(1)))).o $(CFlags)
endef
$(foreach src,$(SOURCE_FILES),$(eval $(call Compile_Source,$(src))))


.PHONY: run clean

# Run the output
run: $(ODIR)/$(NAME).exe
	@$(ODIR)/$(NAME).exe
	

# Clean all object files that have no equivalent source file
__Dirty_Objects=$(foreach pdo,$(wildcard $(OBJDIR)/*),$(if $(filter $(pdo),$(OBJECT_FILES)),,$(pdo)))
define RM_LIST
$(foreach file,$(1),$(MAKE) clean REMOVE_TARGET=$(file))
endef

clean: $(REMOVE_TARGET)
	rm $(__Dirty_Objects)
