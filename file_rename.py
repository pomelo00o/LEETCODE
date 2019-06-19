import os
import re
import sys


def rename_all():
    dir = "./Source"
    file_list = os.listdir(dir)
    os.chdir(dir)
    for file_name in file_list:
        os.rename(file_name, file_name.replace('_', '.'))

    sys.stdin.flush()

rename_all()
