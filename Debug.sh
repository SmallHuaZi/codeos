VM="qemu-system-x86_64"
VM_ARG=""

OS_IOS="build/bin/codeos.ios"
OS_ELF="build/bin/codeos.elf"
OS_DT="assets/codeos.debug"


function main() {
    read run
    case $run in
    1)   runos_in_vm
        ;;
    esac
}


function runos_in_vm() {
    ${VM} ${VM_ARG} ${OS_IOS}
}


function genrtate_debug_table() {
    objcopy --only-keep-debug ${OS_ELF} ${OS_DT}
}


main
