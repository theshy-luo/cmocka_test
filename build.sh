function build_all()
{
    echo "开始编译 $1"

    if [ ! -d "build" ] ; then
        echo "build 目录不存在，创建一个"
        mkdir -p build
    fi

    cd ./build/
    cmake ..
    make -j10
    cd ../
}

function build_clean()
{
    echo "开始清除 $1"

    if [ -d "build" ] ; then
        echo "清除 build 目录"
        rm build -rf
    fi
}

if [ $1 ] ; then
	if [ $1 == "all" ] ; then
		build_all $1
	elif [ $1 == "clean" ] ; then
		build_clean $1
	else
		echo "************ 错误, build.sh all 或者 build.sh clean, 参数错误 ******************"
	fi
else
	echo "************ 错误, build.sh all 或者 build.sh clean, 参数不能为空 ******************"
fi