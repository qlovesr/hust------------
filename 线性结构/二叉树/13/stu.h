#include<string.h>
// 辅助递归函数，放在文件最前面
static void writeNode(BiTree t, FILE *f) {
    if (!t) {
        fprintf(f, "0 null\n");
        return;
    }
    fprintf(f, "%d %s\n", t->data.key, t->data.others);
    writeNode(t->lchild, f);
    writeNode(t->rchild, f);
}

static void readNode(BiTree &t, FILE *f) {
    int key;
    char others[20];
    if (fscanf(f, "%d%s", &key, others) != 2 || key == 0) {
        t = NULL;
        return;
    }
    t = (BiTree)malloc(sizeof(BiTNode));
    t->data.key = key;
    strcpy(t->data.others, others);
    readNode(t->lchild, f);
    readNode(t->rchild, f);
}

status SaveBiTree(BiTree T, char FileName[])
{
    FILE *fp = fopen(FileName, "w");
    if (!fp) return ERROR;
    writeNode(T, fp);
    fclose(fp);
    return OK;
}

status LoadBiTree(BiTree &T, char FileName[])
{
    FILE *fp = fopen(FileName, "r");
    if (!fp) return ERROR;
    readNode(T, fp);
    fclose(fp);
    return OK;
}