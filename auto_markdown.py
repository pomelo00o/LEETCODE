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
        print("Finished tasks = ", len(file_list))
        file_to_remove = ".DS_Store"
        if ".DS_Store" in file_list:
            file_list.remove(file_to_remove)

        file_list.sort(key = take_curr_index)

        start_pos = content.index('## <a name = "solution" /> Solution') + 1
        content.insert(start_pos, "")
        end_pos = content.index('### CopyRight All Rights Reserved.')
        content = content[: start_pos] + content[end_pos:]

        for file_name in file_list:
            file_path = dir + '/' + file_name
            name_in_md = file_name.replace('.', '-')
            lines = '+ [`' + name_in_md[:len(name_in_md) - 4] + '`](' + file_path + ')'
            if lines not in content:
                content.insert(start_pos, lines)
                start_pos += 1

        content.insert(start_pos, "")
        insert = "\n".join(content)
        f.write(insert)


add_file()
