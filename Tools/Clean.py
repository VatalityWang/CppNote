import os

if __name__=='__main__':
    total_num=0
    folder_path='E:/Tencent Files/1225228598/Image/Group2'
    h =os.walk(folder_path)
    for path,dir_list,file_list in h:
        for file in file_list:
            cur_file_path=os.path.join(path,file)
            size = os.path.getsize(cur_file_path)
            if size<500*1024:
                os.remove(cur_file_path)
                print('remove cur_file_path {}'.format(cur_file_path))
                total_num+=1
    print('total remove {} files'.format(total_num))

 
