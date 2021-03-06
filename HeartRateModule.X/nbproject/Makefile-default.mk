#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/HeartRateModule.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/HeartRateModule.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=xlcd/readdata.c xlcd/setcgram.c xlcd/writdata.c xlcd/wcmdxlcd.c xlcd/putrxlcd.c xlcd/busyxlcd.c xlcd/setddram.c xlcd/readaddr.c xlcd/openxlcd.c xlcd/putsxlcd.c xlcd/HeartRateMain.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/xlcd/readdata.o ${OBJECTDIR}/xlcd/setcgram.o ${OBJECTDIR}/xlcd/writdata.o ${OBJECTDIR}/xlcd/wcmdxlcd.o ${OBJECTDIR}/xlcd/putrxlcd.o ${OBJECTDIR}/xlcd/busyxlcd.o ${OBJECTDIR}/xlcd/setddram.o ${OBJECTDIR}/xlcd/readaddr.o ${OBJECTDIR}/xlcd/openxlcd.o ${OBJECTDIR}/xlcd/putsxlcd.o ${OBJECTDIR}/xlcd/HeartRateMain.o
POSSIBLE_DEPFILES=${OBJECTDIR}/xlcd/readdata.o.d ${OBJECTDIR}/xlcd/setcgram.o.d ${OBJECTDIR}/xlcd/writdata.o.d ${OBJECTDIR}/xlcd/wcmdxlcd.o.d ${OBJECTDIR}/xlcd/putrxlcd.o.d ${OBJECTDIR}/xlcd/busyxlcd.o.d ${OBJECTDIR}/xlcd/setddram.o.d ${OBJECTDIR}/xlcd/readaddr.o.d ${OBJECTDIR}/xlcd/openxlcd.o.d ${OBJECTDIR}/xlcd/putsxlcd.o.d ${OBJECTDIR}/xlcd/HeartRateMain.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/xlcd/readdata.o ${OBJECTDIR}/xlcd/setcgram.o ${OBJECTDIR}/xlcd/writdata.o ${OBJECTDIR}/xlcd/wcmdxlcd.o ${OBJECTDIR}/xlcd/putrxlcd.o ${OBJECTDIR}/xlcd/busyxlcd.o ${OBJECTDIR}/xlcd/setddram.o ${OBJECTDIR}/xlcd/readaddr.o ${OBJECTDIR}/xlcd/openxlcd.o ${OBJECTDIR}/xlcd/putsxlcd.o ${OBJECTDIR}/xlcd/HeartRateMain.o

# Source Files
SOURCEFILES=xlcd/readdata.c xlcd/setcgram.c xlcd/writdata.c xlcd/wcmdxlcd.c xlcd/putrxlcd.c xlcd/busyxlcd.c xlcd/setddram.c xlcd/readaddr.c xlcd/openxlcd.c xlcd/putsxlcd.c xlcd/HeartRateMain.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/HeartRateModule.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F452
MP_PROCESSOR_OPTION_LD=18f452
MP_LINKER_DEBUG_OPTION= -u_DEBUGCODESTART=0x7dc0 -u_DEBUGCODELEN=0x240 -u_DEBUGDATASTART=0x5f4 -u_DEBUGDATALEN=0xb
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/xlcd/readdata.o: xlcd/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/readdata.o.d 
	@${RM} ${OBJECTDIR}/xlcd/readdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/readdata.o   xlcd/readdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/readdata.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/readdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/setcgram.o: xlcd/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/setcgram.o.d 
	@${RM} ${OBJECTDIR}/xlcd/setcgram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/setcgram.o   xlcd/setcgram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/setcgram.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/setcgram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/writdata.o: xlcd/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/writdata.o.d 
	@${RM} ${OBJECTDIR}/xlcd/writdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/writdata.o   xlcd/writdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/writdata.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/writdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/wcmdxlcd.o: xlcd/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/wcmdxlcd.o.d 
	@${RM} ${OBJECTDIR}/xlcd/wcmdxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/wcmdxlcd.o   xlcd/wcmdxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/wcmdxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/wcmdxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/putrxlcd.o: xlcd/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/putrxlcd.o.d 
	@${RM} ${OBJECTDIR}/xlcd/putrxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/putrxlcd.o   xlcd/putrxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/putrxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/putrxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/busyxlcd.o: xlcd/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/busyxlcd.o.d 
	@${RM} ${OBJECTDIR}/xlcd/busyxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/busyxlcd.o   xlcd/busyxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/busyxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/busyxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/setddram.o: xlcd/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/setddram.o.d 
	@${RM} ${OBJECTDIR}/xlcd/setddram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/setddram.o   xlcd/setddram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/setddram.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/setddram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/readaddr.o: xlcd/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/readaddr.o.d 
	@${RM} ${OBJECTDIR}/xlcd/readaddr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/readaddr.o   xlcd/readaddr.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/readaddr.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/readaddr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/openxlcd.o: xlcd/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/openxlcd.o.d 
	@${RM} ${OBJECTDIR}/xlcd/openxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/openxlcd.o   xlcd/openxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/openxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/openxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/putsxlcd.o: xlcd/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/putsxlcd.o.d 
	@${RM} ${OBJECTDIR}/xlcd/putsxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/putsxlcd.o   xlcd/putsxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/putsxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/putsxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/HeartRateMain.o: xlcd/HeartRateMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/HeartRateMain.o.d 
	@${RM} ${OBJECTDIR}/xlcd/HeartRateMain.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/HeartRateMain.o   xlcd/HeartRateMain.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/HeartRateMain.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/HeartRateMain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/xlcd/readdata.o: xlcd/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/readdata.o.d 
	@${RM} ${OBJECTDIR}/xlcd/readdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/readdata.o   xlcd/readdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/readdata.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/readdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/setcgram.o: xlcd/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/setcgram.o.d 
	@${RM} ${OBJECTDIR}/xlcd/setcgram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/setcgram.o   xlcd/setcgram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/setcgram.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/setcgram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/writdata.o: xlcd/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/writdata.o.d 
	@${RM} ${OBJECTDIR}/xlcd/writdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/writdata.o   xlcd/writdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/writdata.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/writdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/wcmdxlcd.o: xlcd/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/wcmdxlcd.o.d 
	@${RM} ${OBJECTDIR}/xlcd/wcmdxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/wcmdxlcd.o   xlcd/wcmdxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/wcmdxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/wcmdxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/putrxlcd.o: xlcd/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/putrxlcd.o.d 
	@${RM} ${OBJECTDIR}/xlcd/putrxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/putrxlcd.o   xlcd/putrxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/putrxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/putrxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/busyxlcd.o: xlcd/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/busyxlcd.o.d 
	@${RM} ${OBJECTDIR}/xlcd/busyxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/busyxlcd.o   xlcd/busyxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/busyxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/busyxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/setddram.o: xlcd/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/setddram.o.d 
	@${RM} ${OBJECTDIR}/xlcd/setddram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/setddram.o   xlcd/setddram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/setddram.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/setddram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/readaddr.o: xlcd/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/readaddr.o.d 
	@${RM} ${OBJECTDIR}/xlcd/readaddr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/readaddr.o   xlcd/readaddr.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/readaddr.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/readaddr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/openxlcd.o: xlcd/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/openxlcd.o.d 
	@${RM} ${OBJECTDIR}/xlcd/openxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/openxlcd.o   xlcd/openxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/openxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/openxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/putsxlcd.o: xlcd/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/putsxlcd.o.d 
	@${RM} ${OBJECTDIR}/xlcd/putsxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/putsxlcd.o   xlcd/putsxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/putsxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/putsxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/xlcd/HeartRateMain.o: xlcd/HeartRateMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xlcd" 
	@${RM} ${OBJECTDIR}/xlcd/HeartRateMain.o.d 
	@${RM} ${OBJECTDIR}/xlcd/HeartRateMain.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/xlcd/HeartRateMain.o   xlcd/HeartRateMain.c 
	@${DEP_GEN} -d ${OBJECTDIR}/xlcd/HeartRateMain.o 
	@${FIXDEPS} "${OBJECTDIR}/xlcd/HeartRateMain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/HeartRateModule.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_PK3=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}/../lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/HeartRateModule.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/HeartRateModule.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}/../lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/HeartRateModule.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
