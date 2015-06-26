# 2014-12-24
# build by qianqians
# rpcmake

import os

import deletenote
import statemachine
import codegen

def traversalclass(dirpath):
    filelist = {}

    for filename in os.listdir(dirpath):
        fname = os.path.splitext(filename)[0]
        fex = os.path.splitext(filename)[1]
        if fex == '.juggle':
            file = open(dirpath+filename, 'r')
            genfilestr = deletenote.deletenote(file.readlines())

            smc = statemachine.statemachine()
            smc.syntaxanalysis(genfilestr)
            module = smc.getmodule()
            struct = smc.getstruct()

            filelist[fname] = {}
            filelist[fname]['module'] = module
            filelist[fname]['struct'] = struct

    codegen.codegenclient(filelist)
    codegen.codegenserver(filelist)
    codegen.codegenstruct(filelist)


traversalclass('./')