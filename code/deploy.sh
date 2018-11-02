#!/bin/bash

DEPLOY_PATH="."
cd $DEPLOY_PATH
DEPLOY_PATH=`pwd`
BUILD_PATH="${DEPLOY_PATH}/thirdlib"
NEBULA_BOOTSTRAP="NebulaBeacon NebulaInterface NebulaLogic"
chmod u+x *.sh

function Usage()
{
    echo "Usage: $0 [OPTION]..."
    echo "options:"
    echo -e "  -h, --help\t\t\tdisplay this help and exit."
    echo -e "  -v, --version\t\t\tdisplay nebula version and exit."
    echo -e "  -L, --local\t\t\tdeploy from local without download any files from internet."
    echo -e "      --only-nebula\t\tonly thirdlib Nebula and NebulaBootstrap."
    echo -e "      --with-ssl\t\tinclude openssl for ssl and crypto. [default: without ssl]"
    echo -e "      --with-custom-ssl\t\tinclude openssl for ssl and crypto, the openssl is a custom installation version. [default: without ssl]"
    echo -e "      --with-ssl-include\tthe openssl include path."
    echo -e "      --with-ssl-lib\t\tthe openssl library path."
    echo "example:"
    echo "  $0 --local --with-ssl --with-ssl-lib /usr/local/lib64 --with-ssl-include /usr/local/include"
    echo ""
}

DEPLOY_ONLY_NEBULA=false
DEPLOY_LOCAL=false
DEPLOY_WITH_SSL=false
DEPLOY_WITH_CUSTOM_SSL=false
SSL_INCLUDE_PATH=""
SSL_LIB_PATH=""
ARGV_DEFINE=`getopt \
    -o hvL \
    --long help,version,local,only-nebula,with-ssl,with-custom-ssl,with-ssl-include:,with-ssl-lib: \
    -n 'deploy.bash' \
    -- "$@"`
if [ $? != 0 ]
then
    echo "Terminated!" >&2
    exit 1
fi
eval set -- "$ARGV_DEFINE"

while :
do
    case "$1" in
        -h|--help)
            Usage
            exit 0
            ;;
        -v|--version)
            echo "0.3"
            exit 0
            ;;
        --only-nebula)
            echo "Only thirdlib Nebula and NebulaBootstrap."
            DEPLOY_ONLY_NEBULA=true
            shift
            ;;
        -L|--local)
            echo "Deploy from local without download any files from internet."
            DEPLOY_LOCAL=true
            shift
            ;;
        --with-ssl)
            DEPLOY_WITH_SSL=true
            shift
            ;;
        --with-custom-ssl)
            DEPLOY_WITH_CUSTOM_SSL=true
            shift
            ;;
        --with-ssl-include)
            SSL_INCLUDE_PATH=$2
            DEPLOY_WITH_SSL=true
            shift 2
            ;;
        --with-ssl-lib)
            SSL_LIB_PATH=$2
            DEPLOY_WITH_SSL=true
            shift 2
            ;;
        --)
            shift
            break
            ;;
        *)
            echo "invalid argument!"
            break
            ;;
    esac
done

replace_config="yes"
build_dir_num=`ls -l ${DEPLOY_PATH}/thirdlib | wc -l`
if $DEPLOY_ONLY_NEBULA
then
    echo "please input the thirdlib path[\"enter\" when using default thirdlib path]:"
    read build_path
    if [ ! -z "$build_path" ]
    then
        BUILD_PATH="$build_path"
    fi

    echo "do you want to replace all the config files with the original config files in thirdlib path? [yes | no]"
    read replace_config
else                # deploy remote
    cd ${BUILD_PATH}
    # install protobuf
    if [ -f v3.6.0.zip ]
    then
        echo "protobuf-3.6.0 exist, skip download."
    else
        wget https://github.com/google/protobuf/archive/v3.6.0.zip
        if [ $? -ne 0 ]
        then
            echo "failed to download protobuf!" >&2
            exit 2
        fi
    fi

    unzip v3.6.0.zip
    cd protobuf-3.6.0
    chmod u+x autogen.sh
    ./autogen.sh
    ./configure --prefix=${BUILD_PATH}
    make
    make install
    if [ $? -ne 0 ]
    then
        echo "failed, teminated!" >&2
        exit 2
    fi

    # install libev
    cd ${BUILD_PATH}
    if ! $DEPLOY_LOCAL
    then
        if [ -f libev.zip ]
        then
            echo "libev exist, skip download."
        else
            wget https://github.com/kindy/libev/archive/master.zip
            if [ $? -ne 0 ]
            then
                echo "failed to download libev!" >&2
                exit 2
            fi
            mv master.zip libev.zip
        fi

        unzip libev.zip
        mv libev-master libev
        cd libev/src
        chmod u+x autogen.sh
        ./autogen.sh
        ./configure --prefix=${BUILD_PATH}
        make
        make install
        if [ $? -ne 0 ]
        then
            echo "failed, teminated!" >&2
            exit 2
        fi
        cd ${BUILD_PATH}
    fi

    # install hiredis
    cd ${BUILD_PATH}
    if ! $DEPLOY_LOCAL
    then
        if [ -f hiredis_v0.13.0.zip ]
        then
            echo "directory hiredis exist, skip download."
        else
            wget https://github.com/redis/hiredis/archive/v0.13.0.zip
            if [ $? -ne 0 ]
            then
                echo "failed to download hiredis!" >&2
                exit 2
            fi
            mv v0.13.0.zip hiredis_v0.13.0.zip
        fi

        unzip hiredis_v0.13.0.zip
        mv hiredis-0.13.0 hiredis
        cd hiredis
        make
        mkdir -p ../include/hiredis
        cp -r adapters *.h ../include/hiredis/
        cp libhiredis.so ../lib/
        if [ $? -ne 0 ]
        then
            echo "failed, teminated!" >&2
            exit 2
        fi
    fi

    # install openssl
    if $DEPLOY_WITH_CUSTOM_SSL
    then
        cd ${BUILD_PATH}
        if ! $DEPLOY_LOCAL
        then
            if [ -f OpenSSL_1_1_0.zip ]
            then
                echo "openssl-OpenSSL_1_1_0 exist, skip download."
            else
                wget https://github.com/openssl/openssl/archive/OpenSSL_1_1_0.zip
                if [ $? -ne 0 ]
                then
                    echo "failed to download openssl!" >&2
                    exit 2
                fi
            fi

            unzip OpenSSL_1_1_0.zip
            cd openssl-OpenSSL_1_1_0
            ./config --prefix=${BUILD_PATH}
            make
            make install
            if [ $? -ne 0 ]
            then
                echo "failed, teminated!" >&2
                exit 2
            fi
        fi
    fi

    # install crypto++
    cd ${BUILD_PATH}
    if ! $DEPLOY_LOCAL
    then
        if [ -f CRYPTOPP_6_0_0.tar.gz ]
        then
            echo "cryptopp-CRYPTOPP_6_0_0 exist, skip download."
        else
            wget https://github.com/weidai11/cryptopp/archive/CRYPTOPP_6_0_0.tar.gz
            if [ $? -ne 0 ]
            then
                echo "failed to download crypto++!" >&2
                exit 2
            fi
        fi

        tar -zxvf CRYPTOPP_6_0_0.tar.gz
        cd cryptopp-CRYPTOPP_6_0_0
        make libcryptopp.so
        mkdir -p ../include/cryptopp
        cp *.h ../include/cryptopp/
        cp libcryptopp.so ../lib/
        if [ $? -ne 0 ]
        then
            echo "failed, teminated!" >&2
            exit 2
        fi
    fi
fi
