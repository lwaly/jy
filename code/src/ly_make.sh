#!/bin/bash
mode=$1
WORK_PATH=`pwd`

dest_dir=`dirname $WORK_PATH`
function rotate_dir()
{
    local current_dir=`pwd`
    local target_dir=$1
    local plugin_path=$2
    local is_change_makefile=$3
    cd "$target_dir"
    local found_dirs=`ls -l | grep "^d" | awk '{print $NF}'`
    local sub_dirs=${found_dirs}
    #echo "sub_dirs = {${sub_dirs}}"
    if [ -n "${sub_dirs}" ]
    then
        for d in $sub_dirs
        do
            rotate_dir $d $plugin_path $is_change_makefile
        done
    fi
    if [ -f Makefile ] #-o -f makefile ]
    then
        make_dir=`pwd`
        if [ "$is_change_makefile" = "Y" ]
        then
            makefile_source_dir=`echo "${make_dir}" | awk -F"IM3.0/" '{print $1}'`
            make_dir_depth=`echo "${make_dir}" | awk -F"IM3.0/" '{print $2}' | awk -F/ '{print NF}'`
        fi
        echo "make in ${make_dir} $mode"
        make -j8 $mode
        if [ "$?" != "0" ];
        then
            exit 1
        fi
        if [ "$mode" = "all" ] || [ "$mode" = "" ]
        then
			mkdir -p ${plugin_path}/
            cp -f *.so ${plugin_path}/
        fi
    fi
    cd $current_dir
}

while read src_path dest_path change_makefile others
do
    rotate_dir ${WORK_PATH}/${src_path} ${dest_dir}/${dest_path} ${change_makefile}
    #cd ${src_path}/src
    #cmd_dirs=`ls -l | grep "^d" | awk '{print $NF}'`
    #for d in ${cmd_dirs}
    #do
    #    cd $d
    #    echo "make in `pwd`"
    #    make clean; make -j8
    #    cp *.so ${dest_path}/
    #    cd -
    #done
    #cd ${WORK_PATH}
done < ly_make.conf

