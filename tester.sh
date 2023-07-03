#!/bin/bash

make re

clear

for file in XML/*.sbml
do
    ./SBMLparser $file > tmp
    return_value=$?
    cmp -s tmp $file.res
    compare=$?
    echo -en "SBMLparser $file\treturn value: "
    if [ $return_value -eq 0 ]
    then
        echo -en "\e[92mOK\e[0m"
    else
        echo -en "\e[91mKO\e[0m"
    fi
    echo -n " output: "
    if [ $compare -eq 0 ]
    then
        echo -e "\e[92mOK\e[0m"
    else
        echo -e "\e[91mKO\e[0m"
    fi
    rm tmp
done

    ./SBMLparser XML/other.sbml -i Cytosol > tmp
    return_value=$?
    cmp -s tmp XML/Cytosol.res
    compare=$?
    echo -en "SBMLparser -i Cytosol\t\treturn value: "
    if [ $return_value -eq 0 ]
    then
        echo -en "\e[92mOK\e[0m"
    else
        echo -en "\e[91mKO\e[0m"
    fi
    echo -n " output: "
    if [ $compare -eq 0 ]
    then
        echo -e "\e[92mOK\e[0m"
    else
        echo -e "\e[91mKO\e[0m"
    fi
    rm tmp

    ./SBMLparser XML/other.sbml -i Compound414 > tmp
    return_value=$?
    cmp -s tmp XML/Compound414.res
    compare=$?
    echo -en "SBMLparser -i Compound414\treturn value: "
    if [ $return_value -eq 0 ]
    then
        echo -en "\e[92mOK\e[0m"
    else
        echo -en "\e[91mKO\e[0m"
    fi
    echo -n " output: "
    if [ $compare -eq 0 ]
    then
        echo -e "\e[92mOK\e[0m"
    else
        echo -e "\e[91mKO\e[0m"
    fi
    rm tmp

    ./SBMLparser XML/other.sbml -i Reaction1232 > tmp
    return_value=$?
    cmp -s tmp XML/Reaction1232.res
    compare=$?
    echo -en "SBMLparser -i Reaction1232\treturn value: "
    if [ $return_value -eq 0 ]
    then
        echo -en "\e[92mOK\e[0m"
    else
        echo -en "\e[91mKO\e[0m"
    fi
    echo -n " output: "
    if [ $compare -eq 0 ]
    then
        echo -e "\e[92mOK\e[0m"
    else
        echo -e "\e[91mKO\e[0m"
    fi
    rm tmp

    ./SBMLparser XML/other.sbml -i ChuckNorris > tmp
    return_value=$?
    cmp -s tmp XML/ChuckNorris.res
    compare=$?
    echo -en "SBMLparser -i ChuckNorris\treturn value: "
    if [ $return_value -eq 0 ]
    then
        echo -en "\e[92mOK\e[0m"
    else
        echo -en "\e[91mKO\e[0m"
    fi
    echo -n " output: "
    if [ $compare -eq 0 ]
    then
        echo -e "\e[92mOK\e[0m"
    else
        echo -e "\e[91mKO\e[0m"
    fi
    rm tmp

    ./SBMLparser XML/react.sbml -i Reaction1232 -e > tmp
    return_value=$?
    cmp -s tmp XML/non_reversible.res
    compare=$?
    echo -en "SBMLparser -i Reaction1232 -e\treturn value: "
    if [ $return_value -eq 0 ]
    then
        echo -en "\e[92mOK\e[0m"
    else
        echo -en "\e[91mKO\e[0m"
    fi
    echo -n " output: "
    if [ $compare -eq 0 ]
    then
        echo -e "\e[92mOK\e[0m"
    else
        echo -e "\e[91mKO\e[0m"
    fi
    rm tmp

    ./SBMLparser XML/react.sbml -i Reaction1231 -e > tmp
    return_value=$?
    cmp -s tmp XML/reversible.res
    compare=$?
    echo -en "SBMLparser -i Reaction1231 -e\treturn value: "
    if [ $return_value -eq 0 ]
    then
        echo -en "\e[92mOK\e[0m"
    else
        echo -en "\e[91mKO\e[0m"
    fi
    echo -n " output: "
    if [ $compare -eq 0 ]
    then
        echo -e "\e[92mOK\e[0m"
    else
        echo -e "\e[91mKO\e[0m"
    fi
    rm tmp