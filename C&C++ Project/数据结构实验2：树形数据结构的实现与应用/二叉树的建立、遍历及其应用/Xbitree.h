#pragma once

#ifndef ElemType
#define ElemType char
#endif
#ifndef bt
#define bt "%c"
#endif
#ifndef MaxSaveSize
#define MaxSaveSize 100
#endif

typedef struct BTNode {
	ElemType data;
	struct BTNode* left;
	struct BTNode* right;
}BiTreeNode;

#define stype BiTreeNode*
#define type BiTreeNode*
#include "Xstack.h"
#include "Xqueue.h"

// ��ʼ��������������ͷ�ڵ�
int BiTreeInitiate(BiTreeNode** root, ElemType data) {
	*root = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	if (*root == NULL) {
		printf("��ʼ��������������ͷ�ڵ�ʱ�����ڴ��ʧ�ܣ�\n");
		return 0;
	}
	(*root)->left = NULL;
	(*root)->right = NULL;
	(*root)->data = data;
	return 1;
}

// ��ʼ��������������ͷ�ڵ㣨����ʼ����Ԫ�ص����غ�����
int BiTreeInitiate(BiTreeNode** root) {
	*root = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	if (*root == NULL) {
		printf("��ʼ��������������ͷ�ڵ�ʱ�����ڴ��ʧ�ܣ�\n");
		return 0;
	}
	(*root)->left = NULL;
	(*root)->right = NULL;
	return 1;
}

// �����ڵ�
int LeftInsert(BiTreeNode** curr, ElemType data) {
	if (*curr == NULL) {
		return 0;
	}
	BiTreeNode* newleft, *oldleft;
	oldleft = (*curr)->left;
	newleft = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	if (newleft == NULL) {
		printf("��ڵ��ڴ����ʧ�ܣ�\n");
		return 0;
	}
	newleft->data = data;
	newleft->left = oldleft; // ��ԭ��ڵ���Ϊ����ڵ��������
	newleft->right = NULL;
	(*curr)->left = newleft;
	return 1;
}

// �Ҳ���ڵ�
int RightInsert(BiTreeNode** curr, ElemType data) {
	if (*curr == NULL) {
		return 0;
	}
	BiTreeNode* newright, * oldright;
	oldright = (*curr)->right;
	newright = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	if (newright == NULL) {
		printf("�ҽڵ��ڴ����ʧ�ܣ�\n");
		return 0;
	}
	newright->data = data;
	newright->left = oldright; // ��ԭ�ҽڵ���Ϊ���ҽڵ��������
	newright->right = NULL;
	(*curr)->right = newright;
	return 1;
}

// �ͷ���
void BiTreeDestory(BiTreeNode** root) {
	if (*root != NULL) { // ������ڵ㲻Ϊ��  
		// �ȵݹ�����������  
		BiTreeDestory(&(*root)->left);
		// �ٵݹ�����������  
		BiTreeDestory(&(*root)->right);
		// ����ͷŸ��ڵ�  
		free(*root);
		// ���ø��ڵ�ָ��ΪNULL����ֹ����ָ��  
		*root = NULL;
	}
}

// ɾ��������
int LeftDelete(BiTreeNode** curr) {
	if (*curr == NULL || (*curr)->left == NULL)
		return 0;
	BiTreeDestory(&(*curr)->left);
	(*curr)->left = NULL;
	return 1;
}

// ɾ��������
int RightDelete(BiTreeNode** curr) {
	if (*curr == NULL || (*curr)->right == NULL)
		return 0;
	BiTreeDestory(&(*curr)->right);
	(*curr)->right = NULL;
	return 1;
}

// ʹ��ǰ׺���ʽ������������'#'��ʾ��
int BiTreeCreate(BiTreeNode** root, const char* str, int* index) {
	if (*index >= strlen(str) || str[*index] == '#') {  
		*root = NULL;
		(*index)++; 
		return 1;
	}
	*root = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	if (!*root) {
		printf("�ڴ����ʧ�ܣ�\n");
		return 0;
	}
	(*root)->data = str[*index];
	(*index)++; // ����������ָ����һ���ַ�  
	if (!BiTreeCreate(&(*root)->left, str, index))// ���������� 
		return 0;  
	if (!BiTreeCreate(&(*root)->right, str, index))// ���������� 
		return 0;   
	return 1; 
}

void BiTreeCreate(BiTreeNode** root, const char* polish) {
	// �������غ���������������β����ж��Ƿ�����ݹ�
	int num = 0;
	BiTreeCreate(root, polish, &num);
}

// ���ļ���ǰ׺���ʽ��ȡ������ �������ڵ�ElemTypeΪcharʱ
int BiTreeReadFile(BiTreeNode** root, const char* path) {
	FILE* fp;
	if (fopen_s(&fp, path, "r") != 0) {
		printf("��%sʧ�ܣ�\n", path);
		return 0;
	}
	fseek(fp, 0, SEEK_END); // ���ļ�ָ���Ƶ��ļ�ĩβ
	long file_size = ftell(fp); // ��ȡ�ļ���С
	fseek(fp, 0, SEEK_SET); // ���ļ�ָ�������Ƶ��ļ���ͷ
	char* polish = (char*)malloc(static_cast<size_t>(file_size) + 1); // ��1���ڴ洢�ַ���������'\0'
	if (polish == NULL) {
		printf("���ļ���ǰ׺���ʽ��ȡ������ʱ�ڴ����ʧ�ܣ�\n");
		fclose(fp);
		return 0;
	}
	fread(polish, 1, file_size, fp);
	polish[file_size] = '\0'; // ����ַ���������
	int num = 0;
	if (!BiTreeCreate(root, polish, &num)) {
		printf("����������ʧ�ܣ�\n");
		free(polish);
		fclose(fp);
		return 0;
	}
	free(polish);
	fclose(fp);
	return 1;
}

void BiTreeSave(BiTreeNode* root, char* str, int* index) {
	if (root == NULL) {
		str[(*index)++] = '#';
		return;
	}
	str[(*index)++] = root->data; 
	BiTreeSave(root->left, str, index);
	BiTreeSave(root->right, str, index);
	str[(*index)] = '\0';
}

int BiTreeWriteFile(BiTreeNode* root, const char* path) {
	char str[MaxSaveSize];
	int index = 0;
	BiTreeSave(root, str, &index);
	FILE* fp;
	if (fopen_s(&fp, path, "w") != 0) {
		printf("��%sʧ�ܣ�\n", path);
		return 0;
	}
	fprintf(fp, "%s", str);
	fclose(fp);
	return 1;
}

// �ð����ʾ����ӡ������������RDL��
void BiTreePrint_RDL(BiTreeNode* root, int n) {
	if (root == NULL)
		return;
	BiTreePrint_RDL(root->right, n + 1);
	for (int i = 0; i < n; i++) {
		printf("   ");
	}
	if (n > 0) {
		printf("����");
	}
	//printf("[%c]\n", root->data);
	printf("[");
	printf(bt, root->data);
	printf("]\n");
	BiTreePrint_RDL(root->left, n + 1);
}

void BiTreePrint_RDL(BiTreeNode* root) {
	BiTreePrint_RDL(root, 0);
}

// �ð����ʾ����ӡ������������
void BiTreePrint_DLR(BiTreeNode* root, int n) {
	if (root == NULL)
		return;
	for (int i = 0; i < n; i++) {
		printf("   ");
	}
	//printf("[%c]\n", root->data);
	printf("[");
	printf(bt, root->data);
	printf("]\n");
	if (root->left != NULL) {
		for (int i = 0; i < n; i++) {
			printf("   ");
		}
		printf("|����Left\n"); 
		BiTreePrint_DLR(root->left, n + 1);
	} 
	if (root->right != NULL) {
		for (int i = 0; i < n; i++) {
			printf("   ");
		}
		printf("|����Right\n"); 
		BiTreePrint_DLR(root->right, n + 1);
	}
}

void BiTreePrint_DLR(BiTreeNode* root) {
	BiTreePrint_DLR(root, 0);
}

// ������������
int BiTreeDepth(BiTreeNode* root, int n) {
	if (root != NULL) {
		n++;
		if (BiTreeDepth(root->left, n) > BiTreeDepth(root->right, n))
			return BiTreeDepth(root->left, n);
		else
			return BiTreeDepth(root->right, n);
	}
	else
		return n;
}

int BiTreeDepth(BiTreeNode* root) {
	return BiTreeDepth(root, -1);
}

// ��ǰָ����ָ�ڵ�ĸ߶�
int BiTreeNowHeight(BiTreeNode* root, BiTreeNode* curr) {
	if (root == NULL) {
		return -1;
	}
	if (root == curr) {
		return 0; 
	}
	int leftDepth = BiTreeNowHeight(root->left, curr);
	if (leftDepth != -1) {
		return leftDepth + 1;
	}
	int rightDepth = BiTreeNowHeight(root->right, curr);
	return rightDepth != -1 ? rightDepth + 1 : -1;
}

// ���ƶ������ڵ�
void BiTreeDrawNode(BiTreeNode* curr, int n, int x, int y) {
	int tw = textwidth(curr->data), th = textheight(curr->data);
	int radius = (tw > th ? tw : th) / 2; // �뾶�ǿ�Ⱥ͸߶��н�Сֵ��һ��  
	int px = x, py = y - th / 2; // �ı�����λ��y�ᣬԲ�������Ե����ı��ײ�  
	circle(px, py + radius, radius); // ����Բ��Բ���Ե����ı��ײ�  
	char data[2] = { curr->data, '\0' };
	outtextxy(px - tw / 2, py, data); // ���ı�����λ������ַ�  
}

// ���ƶ�����
void BiTreeDrawPicture(BiTreeNode* root, int n, int x, int y) {
	if (root == NULL)
		return;
	int tw = textwidth(root->data), th = textheight(root->data);
	int radius = (tw > th ? tw : th) / 2;
	BiTreeDrawNode(root, n, x, y);
	double scaleFactor = pow(0.5, n);
	double minScaleFactor = 0.2; // ��С���Ϊԭʼ����20%  
	scaleFactor = fmax(scaleFactor, minScaleFactor);
	int leftX = x - textwidth(root->data) - (int)(radius * scaleFactor * 4); // ������ˮƽλ��  
	int leftY = y + textheight(root->data) + (int)(radius * 2); // ��ֱ�����ƶ�һ������  
	int rightX = x + textwidth(root->data) + (int)(radius * scaleFactor * 4); // ������ˮƽλ��  
	int rightY = leftY; // ��������������ͬ�Ĵ�ֱ���� 
	if (root->left != NULL) {
		// ���Ƶ�����������  
		line(x - (int)(radius / sqrt(2)), y + (int)(radius / sqrt(2)), leftX + (int)(radius / sqrt(2)), leftY - (int)(radius / sqrt(2)));
		BiTreeDrawPicture(root->left, n + 1, leftX, leftY);
	}
	if (root->right != NULL) {
		// ���Ƶ�����������  
		line(x + (int)(radius / sqrt(2)), y + (int)(radius / sqrt(2)), rightX - (int)(radius / sqrt(2)), rightY - (int)(radius / sqrt(2)));
		BiTreeDrawPicture(root->right, n + 1, rightX, rightY);
	}
}

// ������ͼ���沢���������ͼƬ
void BiTreeDraw(BiTreeNode* root, const char* path) {
	int depth = BiTreeDepth(root);
	int height = (depth + 1) * 150;
	int width = (depth + 1) * 160;
	initgraph(width, height, EX_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);
	settextcolor(BLACK);
	settextstyle(50, 0, "΢���ź�");
	setbkmode(TRANSPARENT);
	BiTreeDrawPicture(root, 0, getwidth() / 2, 50);
	if (strcmp(path, "") != 0) {
		saveimage(path);
		printf("������ͼƬ�ѱ�����%s", path);
	}
	else
		_getch();
	closegraph();
}

// ���ҽڵ�
BiTreeNode* BiTreeSearch(BiTreeNode* root, ElemType x) {
	BiTreeNode* p;
	if (root == NULL) 
		return NULL; // �ݹ����
	if (root->data == x) 
		return root;// �ݹ����
	if (root->left != NULL) { // ��ѯ������
		p = BiTreeSearch(root->left, x);
	if (p != NULL) 
			return p;
	}
	if (root->right != NULL) { // ��ѯ������
		p = BiTreeSearch(root->right, x);
	if (p != NULL) 
			return p;
	}
	return NULL;
}

// �ǵݹ�ʽ���������ʽ
void BiTreeOut_Prefix(BiTreeNode* root) {
	BiTreeNode* p = root;
	SNode* stack;
	StackInitiate(&stack);
	while (p!=NULL || StackNotEmpty(stack)) {
		while (p != NULL) {
			printf(bt, p->data);
			StackPush(stack, p);
			p = p->left;
		}
		if (StackNotEmpty(stack)) {
			StackPop(stack, &p);
			p = p->right;
		}
	}
	StackDestory(&stack);
}

// �ǵݹ�ʽ���������ʽ
void BiTreeOut_Infix(BiTreeNode* root) {
	SNode* stack;
	StackInitiate(&stack);
	BiTreeNode* p = root;
	while (p != NULL || StackNotEmpty(stack)) { 
		while (p != NULL) {
			StackPush(stack, p);
			p = p->left;
		}  
		if (StackPop(stack, &p)) {
			printf(bt, p->data);
		}  
		p = p->right;
	}
	StackDestory(&stack);
}

// �ǵݹ�ʽ���������ʽ
void BiTreeOut_Postfix(BiTreeNode* root) {
	SNode* stack;
	StackInitiate(&stack);
	BiTreeNode* p = root;
	BiTreeNode* prev = NULL; // ��һ�����ʵĽڵ�  
	BiTreeNode* peek; // ��ʱ�洢ջ��Ԫ��  
	while (p != NULL || StackNotEmpty(stack)) {
		// ����������  
		while (p != NULL) {
			StackPush(stack, p);
			p = p->left;
		}
		// ����ջ���ڵ㣬����������ӡ�����ҵ������������ҽڵ�  
		while (StackNotEmpty(stack)) {
			StackPop(stack, &peek);
			// ���peek�����ӽڵ���δ�����ʹ�������peekû�����ӽڵ�  
			if (peek->right == NULL || peek->right == prev) {
				printf("%c", peek->data);
				prev = peek; // ����prevΪ��ǰ�ڵ�  
				break;  
			}
			// ����peek����ѹ��ջ�У�����������������  
			StackPush(stack, peek);
			p = peek->right;
			while (p != NULL) {
				StackPush(stack, p);
				p = p->left;
			}
		}
		// ���pΪ�գ�˵����ǰջ�еĽڵ㶼û�����ӽڵ�������ӽڵ㶼�Ѿ������ʹ���  
		p = NULL;
	}
	StackDestory(&stack);
}

// �ݹ�ʽ����������ʽ
void BiTreeTrav_Prefix(BiTreeNode* root, void visit(ElemType item)) {
	if (root != NULL) {
		visit(root->data);
		BiTreeTrav_Prefix(root->left, visit);
		BiTreeTrav_Prefix(root->right, visit);
	}
}

// �ݹ�ʽ����������ʽ
void BiTreeTrav_Infix(BiTreeNode* root, void visit(ElemType item)) {
	if (root != NULL) {
		BiTreeTrav_Infix(root->left, visit);
		visit(root->data);
		BiTreeTrav_Infix(root->right, visit);
	}
}

// �ݹ�ʽ����������ʽ
void BiTreeTrav_Postfix(BiTreeNode* root, void visit(ElemType item)) {
	if (root != NULL) {
		BiTreeTrav_Infix(root->left, visit);
		BiTreeTrav_Infix(root->right, visit);
		visit(root->data);
	}
}

// �������Ĳ������
void BiTreeTrav_Leve(BiTreeNode* root, void visit(ElemType item)) {
	Queue queue;
	QueueInitiate(&queue);
	BiTreeNode* p = root;
	if (p != NULL) {
		QueueAppend(&queue, p); // ��������
		while (QueueNotEmpty(queue)) {
			QueueDelete(&queue, &p);
			visit(p->data);
			if (p->left != NULL)
				QueueAppend(&queue, p->left); // �������
			if (p->right != NULL)
				QueueAppend(&queue, p->right); // �ҽ�����
		}
	}
	QueueDestory(&queue);
}

void BiTreeLeaf(BiTreeNode* root, void visit(ElemType item), bool isleap) {
	if (root == NULL)
		return;
	BiTreeNode* p = root;
	if (isleap == true) {
		if (p->left == NULL && p->right == NULL)
			visit(root->data);
		BiTreeLeaf(root->left, visit, true);
		BiTreeLeaf(root->right, visit, true);
	}
	else {
		if(p->left != NULL || p->right != NULL)
			visit(root->data);
		BiTreeLeaf(root->left, visit, false);
		BiTreeLeaf(root->right, visit, false);
	}
}

// �ж���ȫ������
bool BiTreeComplete(BiTreeNode* root) {
	if (root == NULL)
		return true;
	Queue queue;
	QueueInitiate(&queue);
	BiTreeNode* p = root;
	bool metNull = false; 
	QueueAppend(&queue, p); 
	while (QueueNotEmpty(queue)) {
		QueueDelete(&queue, &p);
		if (p == NULL) {
			// ��������˿սڵ㣬���ñ�ǲ������������������Ƿ��зǿսڵ�  
			metNull = true;
			continue;
		}
		// ����Ѿ������˿սڵ㣬����ǰ�ڵ㲻Ϊ�գ�������ȫ������  
		if (metNull) {
			return false;
		}
		QueueAppend(&queue, p->left);
		QueueAppend(&queue, p->right);
	}
	QueueDestory(&queue);
	return true;
}

#ifndef MaxBit
#define MaxBit 10
#endif
#ifndef MaxValue
#define MaxValue 10000
#endif

typedef struct HaffNode {
	int weight;
	int flag;
	int parent;
	int left;
	int right;
}HaffNode;

typedef struct HaffCode {
	int bit[MaxBit];
	int start;
	int weight;
}HaffCode;

void HaffmanCreate(int weight[], int n, HaffNode HaffTree[]) {
	int i, j, m1, m2, x1, x2;
	for (i = 0;i < 2 * n - 1;i++) { // ��ʼ������������n��Ҷ�ڵ�Ķ���������2n-1���ڵ�
		if (i < n)
			HaffTree[i].weight = weight[i];
		else
			HaffTree[i].weight = 0;
		HaffTree[i].parent = -1;
		HaffTree[i].flag = 0;
		HaffTree[i].left = -1;
		HaffTree[i].right = -1;
	}
	for (i = 0; i < n - 1; i++) {
		m1 = m2 = MaxValue;
		x1 = x2 = 0;
		for (j = 0;j < n + i;j++) { // �ҳ�Ȩֵ��С�ʹ�С������
			if (HaffTree[j].weight < m1 && HaffTree[j].flag == 0) {
				m2 = m1;
				x2 = x1;
				m1 = HaffTree[j].weight;
				x1 = j;
			}
			else if (HaffTree[j].weight < m2 && HaffTree[j].flag == 0) {
				m2 = HaffTree[j].weight;
				x2 = j;
			}
		}
		// ���ҳ�������Ȩֵ��С�ĺʹ�С�������ϲ�Ϊһ������
		HaffTree[x1].parent = n + i;
		HaffTree[x2].parent = n + i;
		HaffTree[x1].flag = 1;
		HaffTree[x2].flag = 1;
		HaffTree[n + i].weight = HaffTree[x1].weight + HaffTree[x2].weight;
		HaffTree[n + i].left = x1;
		HaffTree[n + i].right = x2;
	}
}

int HaffmanCode(HaffNode haffTree[], int n, HaffCode haffCode[]) {
	HaffCode* cd = (HaffCode*)malloc(sizeof(HaffCode));
	if (cd == NULL)
		return 0;
	int i, j, child, parent;
	for (i = 0; i < n; i++) {
		cd->start = n - 1;
		cd->weight = haffTree[i].weight;
		child = i;
		parent = haffTree[child].parent;
		while (parent != -1) {
			if (haffTree[parent].left == child)
				cd->bit[cd->start] = 0;
			else
				cd->bit[cd->start] = 1;
			cd->start--;
			child = parent;
			parent = haffTree[child].parent;
		}
		for (j = cd->start + 1;j < n;j++)
			haffCode[i].bit[j] = cd->bit[j];
		haffCode[i].start = cd->start + 1;
		haffCode[i].weight = cd->weight;
	}
	return 1;
}