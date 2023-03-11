FS_CATEGORY := ext2
FS_VERSION  := 0.0.1
FS_SRC_PATH := src/fs


FS_SRC := $(wildcard ${FS_SRC_PATH}/*cpp)

${FS_CATEGORY}: ${FS_SRC}
	${CXX} ${CXXFALGS} ${FS_SRC} -o ${TMP_DIR}