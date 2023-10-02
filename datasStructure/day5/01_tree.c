#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct tree {
    //左孩子
    struct tree * left;
    struct tree * right;
    void * data;
}tree_t;

//创建一个二叉树
tree_t * creat_tree(){
    tree_t * tree = NULL;
    return tree;
}


typedef int (*cmpfun)(const void * data1 , const void * data2);
int comnum(const void * data1 , const void * data2){
    int * newdata1 = (int *)data1;
    int * newdata2 = (int *)data2;
    return *newdata1 - *newdata2;
}
//插入节点
int insertTree(tree_t **root , void * newData , int size , cmpfun cmp){
   //参数判断 
    if (newData == NULL || size <= 0 || cmp == NULL)
    {
        printf("参数错误\n");
        return -1;
    }
    if (*root == NULL)
    {
       
        tree_t * newNode = malloc(sizeof(tree_t));
        if (newNode == NULL)
        {
            printf("申请空间失败\n");
            return -1;
        }
        //本指针是否是叶子节点的孩子指针
        //填写数据
       
        newNode->data = malloc(size);
        memcpy(newNode->data , newData , size);
        newNode->left = newNode->right = NULL;
        *root = newNode;
        return 0;
    }
    if (cmp((*root)->data , newData)<0)
    {
        insertTree(&(*root)->right , newData , size , cmp);
    }
    else if (cmp((*root)->data, newData) > 0)
    {
        insertTree(&(*root)->left, newData, size, cmp);
    }else{
        printf("插入的数值相等 \n");
        return -1;
    }
}



typedef int (*showfun_t)(const void * data);

int treePrintf(const void * data){
    const int * newdata = (const int *)data;
    printf("%d " , *newdata);
    return 0;
}

void firstPrintf(tree_t * tree , showfun_t show){
    if (tree == NULL)
    {
        return;
    }
    show(tree->data);
    firstPrintf(tree->left , show);
    firstPrintf(tree->right, show);
}

void midPrintf(tree_t * tree , showfun_t show){
    if (tree == NULL)
    {
        return;
    }
    midPrintf(tree->left ,show);
    show(tree->data);
    midPrintf(tree->right , show);
}

void lastPrintf(tree_t * tree , showfun_t show){
    if (tree == NULL)
    {
        return;
    }
    lastPrintf(tree->left , show);
    lastPrintf(tree->right , show);
    show(tree->data);
    
}

//找到二叉树的最小值
tree_t * findminValueToTree(tree_t * tree){
    if (tree->left == NULL)
    {
        return tree;
    }
    return findminValueToTree(tree->left);
}

//找到二叉树的最大值
tree_t * findMaxValuetoTree(tree_t * tree){
    if (tree->right == NULL)
    {
        return tree ;
    }
    return findMaxValuetoTree(tree->right);
    
}

//查找值
tree_t * findContentByValue(tree_t * tree ,const void *data , cmpfun cmp ){
    if (tree == NULL)
    {
        return NULL;
    }
    
    if (data == NULL || cmp == NULL)
    {
        return NULL;
    }
    tree_t * temp = tree;
    if (temp != NULL)
    {
        if (cmp(temp->data , data) == 0)
        {
            return temp;
        }
        if (cmp(temp->data , data) > 0)
        {
            return findContentByValue(temp->left , data ,cmp);
        }
        if (cmp(temp->data , data) < 0)
        {
            return findContentByValue(temp->right , data , cmp);
        }
    }
    return NULL;
}


//用于连接左右子树，只能用于有序树的连接节点
static tree_t * connectTree(tree_t * left ,tree_t * right){
    if (left == NULL && right != NULL)
    {
        return right;
    }
    if (right == NULL && left != NULL)
    {
        return left;
    }
    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    findMaxValuetoTree(left)->right = right;
    return left;
}
//删除节点 + 比较函数
tree_t * deleteTreeNode(tree_t **tree , const void * data , cmpfun cmp){
    tree_t * left = NULL;
    tree_t * right = NULL;
    if (!cmp((*tree)->data , data))
    {
        //保留左子树和右子树
        left = (*tree)->left;
        right = (*tree)->right;
        //先释放根节点的数据部分
        free((*tree)->data);
        //释放根节点的全部
        free(*tree);
        //再替换主函数变量中的值
        *tree = connectTree(left , right);
        return NULL;
    }
    tree_t * temp = *tree , *parent = NULL;
    int flag = -1;
    while (temp != NULL)
    {
        if (cmp(temp->data,data) > 0)
        {
            //先保留此指针
            parent = temp;
            temp = temp->left;
            flag = 1;
        }else if (cmp(temp->data , data) < 0)
        {
            parent = temp;
            temp = temp->right;
            flag = 0;
        }else{
            break;
        }
    }
    if (temp == NULL)
    {
        printf("没找到\n");
    }else {
        left = temp->left;
        right = temp->right;
        free(temp->data);
        free(temp);
        //
        if (flag == 1)
        {
            parent->left = connectTree(left, right);
        }
        else
        {
            parent->right = connectTree(left, right);
        }
    }
}

//销毁二叉树
void destroyTree(tree_t **tree){
    if (*tree ==  NULL)
    {
        return;
    }
    destroyTree(&(*tree)->left);
    destroyTree(&(*tree)->right);
    free((*tree)->data);
    free(*tree);
    *tree = NULL;
}

int main(int argc, char const *argv[])
{
    tree_t * tree = creat_tree();
    int arr[7] = {5,3,7,8,2,4,6};
    for (int i = 0; i < 7; i++)
    {
        insertTree(&tree , arr+i ,sizeof(int),comnum);
    }
    printf("先序遍历：");
    firstPrintf(tree , treePrintf);printf("\n");
    printf("中序遍历："); 
    midPrintf(tree , treePrintf);printf("\n");
    printf("后续遍历：");
    lastPrintf(tree , treePrintf);printf("\n");
    printf("-----------------找到最大值------------------\n");
    printf("%d \n" , *(int *)(findMaxValuetoTree(tree))->data);
    printf("-----------------找到最小值------------------\n");
    printf("%d \n" , *(int *)(findminValueToTree(tree))->data);
    printf("-----------------查找元素------------------\n");
    int index = 0;
    printf("查找的数据:");
    scanf("%d" , &index);
    getchar();
    tree_t * temp = findContentByValue(tree , &index , comnum);
    if (temp != NULL)
    {
        printf("找到了，值为： %d\n" , *(int *)(temp->data));
    }else{
        printf("没找到\n");
    }
    printf("------------------删除二叉树----------------\n");
    destroyTree(&tree);
    printf("%p\n" , tree);
    
    return 0;
}
