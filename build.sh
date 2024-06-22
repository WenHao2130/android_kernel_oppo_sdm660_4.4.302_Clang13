clear
rm -rf out/
rm -rf kernel_log.log
# git reset --hard 199b37942632a3fb21cd4b90fc4e17132e73570a
# git pull
# git cherry-pick 9e6760d2d2703ed86908422da6a7f89547cd55f8
export ARCH="arm64"
export OPPO_TARGET_DEVICE="MSM_16051"
export CROSS_COMPILE=aarch64-linux-android-
export PATH=$PATH:/workspaces/gcc/aarch64-linux-android-4.9/bin
# vim ./include/linux/compiler-gcc.h
clear
make O=out sdm660-perf_defconfig
make ARCH=arm64 O=out -j8 2>&1 | tee kernel_log.log