import os


def take_curr_index(elem):
    return int(elem.split(".")[0])


def add_file():
    file_name = "README.md"
    with open(file_name, "r") as f:
        content = f.read().split('\n')

    with open(file_name, "w+") as f:
        dir = "./src"
        file_list = os.listdir(dir)
        file_list.sort(key = take_curr_index)

        pos = 10
        for file_name in file_list:
            file_path = dir + '/' + file_name
            name_in_md = file_name.replace('.', '-')
            lines = '+ [`' + name_in_md[:len(name_in_md) - 4] + '`](' + file_path + ')'
            if lines not in content:
                content.insert(pos, lines)
                pos += 1

        insert = "\n".join(content)
        f.write(insert)


add_file()
