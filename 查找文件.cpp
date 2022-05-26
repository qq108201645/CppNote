#include<iostream>
#include <Windows.h>
#include <string>
#include <assert.h>

typedef bool (*FindProc)(const char* chFinleName);

//�����ļ��У�chFolderPathΪҪ�������ļ���·����chFilterΪ�����ļ��еĹ�����������*.txt��
bool FindFolder(const char* chFolderPath, const char* chFilter, bool bFindFolder, FindProc pFindProc)
{
    assert(pFindProc);
    int nPathLen = strlen(chFolderPath) + MAX_PATH;
    char* pChPath = new char[nPathLen];
    sprintf(pChPath,  "%s\\%s", chFolderPath, chFilter);
    WIN32_FIND_DATA fileFindData;
    HANDLE hFind = ::FindFirstFile(pChPath, &fileFindData);            //�ҵ���һ��

    if (hFind == INVALID_HANDLE_VALUE)        //���û���ҵ���ص��ļ���Ϣ������false
    {
        delete pChPath;
        return false;
    }

    //����֮�������һ����ֱ��������
    do
    {
        if (fileFindData.cFileName[0] == '.')
        {
            continue;            //��Ϊ�ļ��п�ʼ��"."��".."����Ŀ¼��Ҫ���˵�
        }

        sprintf(pChPath, "%s\\%s", chFolderPath, fileFindData.cFileName);    //�ļ�������·��

        //���Ҫ���ҵݹ�����ļ���
        if (bFindFolder && (fileFindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            FindFolder(pChPath, chFilter, bFindFolder, pFindProc);            //�ݹ����������������Ŀ¼
        }

        //������ļ�
        pFindProc(pChPath);

    }while (::FindNextFile(hFind, &fileFindData));

    FindClose(hFind);                //�رղ��Ҿ��
    delete pChPath;
    return true;
}

bool PrintFiles(const char* chFileName)
{
    std::cout<< chFileName<<std::endl;
    return true;
}
int main()
{
    FindFolder("D:", "*.*", true, &PrintFiles);
    getchar();
    MessageBox(NULL,TEXT("good"),NULL,TEXT("haha"));
    return 0;
}
