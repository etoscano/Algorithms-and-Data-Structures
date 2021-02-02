#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFLENGHT 1000

typedef struct node
{
    char color;
    struct node *left, *right, *parent;
    char *name;
}node;

typedef struct noderel
{
    struct noderel *next;
    struct nodeone *names;
    char *namerel;
}noderel;

typedef struct nodeone
{
    char color;
    int numrel;
    struct nodeone *left, *right, *parent;
    struct node *root;
    char *name1;
}nodeone;


// Left Rotation
void leftRotate(struct node **root, struct node *x, struct node * NIL)
{
    if (x==NIL || x->right==NIL)
        return ;

    struct node *y = x->right;

    x->right = y->left;

    if (y->left != NIL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NIL) {
        (*root) = y; // TODO CHECK IF NOT ROOT = &Y
    }
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }
    y->left = x;

    x->parent = y;
}


// Right Rotation (Similar to LeftRotate)
void rightRotate(struct node **root,struct node *y, struct node * NIL)
{
    if (y==NIL || y->left==NIL)
        return ;

    struct node *x = y->left;

    y->left = x->right;

    if (x->right != NIL)
        x->right->parent = y;

    x->parent =y->parent;

    if (y->parent == NIL) {
        (*root) = x; // TODO CHECK
    }
    else if (y == y->parent->left) {
        y->parent->left = x;
    }
    else {
        y->parent->right = x;
    }
    x->right = y;

    y->parent = x;
}

// Left Rotation Rel
void leftRotateRel(struct nodeone **root, struct nodeone *x, struct nodeone * NILONE)
{
    if (x==NILONE || x->right==NILONE)
        return ;

    struct nodeone *y = x->right;

    x->right = y->left;

    if (y->left != NILONE)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NILONE) {
        (*root) = y; // TODO CHECK IF NOT ROOT = &Y
    }
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }
    y->left = x;

    x->parent = y;
}


// Right Rotation (Similar to LeftRotate)
void rightRotateRel(struct nodeone **root,struct nodeone *y, struct nodeone * NILONE)
{
    if (y==NILONE || y->left==NILONE)
        return ;

    struct nodeone *x = y->left;

    y->left = x->right;

    if (x->right != NILONE)
        x->right->parent = y;

    x->parent =y->parent;

    if (y->parent == NILONE) {
        (*root) = x; // TODO CHECK
    }
    else if (y == y->parent->left) {
        y->parent->left = x;
    }
    else {
        y->parent->right = x;
    }
    x->right = y;

    y->parent = x;
}


void insertFixUpRel(struct nodeone **root,struct nodeone *z, struct nodeone * NILONE)
{
    struct nodeone *x = NILONE, * y = NILONE;

    if(z == *root){
        (*root)->color = 'B';
    }
    else {
        x = z->parent;
        if (x->color == 'R') {
            if (x == x->parent->left) {
                y = x->parent->right;
                if (y->color == 'R') {
                    x->color = 'B';
                    y->color = 'B';
                    x->parent->color = 'R';
                    insertFixUpRel(root, x->parent,  NILONE);
                } else {
                    if (z == x->right) {
                        z = x;
                        leftRotateRel(root, x, NILONE);
                        x = z->parent;
                    }
                    x->color = 'B';
                    x->parent->color = 'R';
                    rightRotateRel(root, x->parent,NILONE);
                }
            } else {
                y = x->parent->left;
                if (y->color == 'R') {
                    x->color = 'B';
                    y->color = 'B';
                    x->parent->color = 'R';
                    insertFixUpRel(root, x->parent,NILONE);
                } else {
                    if (z == x->left) {
                        z = x;
                        rightRotateRel(root, x,NILONE);
                        x = z->parent;
                    }
                    x->color = 'B';
                    x->parent->color = 'R';
                    leftRotateRel(root, x->parent,NILONE);
                }
            }
        }
    }
}

void insertFixUp(struct node **root,struct node *z, struct node * NIL)
{
    struct node *x = NIL, * y = NIL;

    if(z == *root){
        (*root)->color = 'B';
    }
    else {
        x = z->parent;
        if (x->color == 'R') {
            if (x == x->parent->left) {
                y = x->parent->right;
                if (y->color == 'R') {
                    x->color = 'B';
                    y->color = 'B';
                    x->parent->color = 'R';
                    insertFixUp(root, x->parent, NIL);
                } else {
                    if (z == x->right) {
                        z = x;
                        leftRotate(root, x, NIL);
                        x = z->parent;
                    }
                    x->color = 'B';
                    x->parent->color = 'R';
                    rightRotate(root, x->parent, NIL);
                }
            } else {
                y = x->parent->left;
                if (y->color == 'R') {
                    x->color = 'B';
                    y->color = 'B';
                    x->parent->color = 'R';
                    insertFixUp(root, x->parent, NIL);
                } else {
                    if (z == x->left) {
                        z = x;
                        rightRotate(root, x, NIL);
                        x = z->parent;
                    }
                    x->color = 'B';
                    x->parent->color = 'R';
                    leftRotate(root, x->parent, NIL);
                }
            }
        }
    }
}

int contains(struct node **root,char name[], struct node * NIL){
    if (*root == NIL) {
        return 0;
    } else{
        // if not in here 0
        // if in here 1

        struct node *x = (*root);

        while (x != NIL)
        {
            int val = strcmp(name,x->name);
            if (val<0) {
                x = x->left;
            }
            else if (val>0) {
                x = x->right;
            }
            else if(val==0){
                return 1;
            }
        }
        return 0;
    }
}
node* find(struct node **root,char name[], struct node * NIL){
    if (*root == NIL) {
        return NIL;
    } else{
        // if not in here 0
        // if in here 1

        struct node *x = (*root);

        while (x != NIL)
        {
            int val = strcmp(name,x->name);
            if (val<0) {
                x = x->left;
            }
            else if (val>0) {
                x = x->right;
            }
            else if(val==0){
                return x;
            }
        }
        return NIL;
    }
}
nodeone* findOne(struct nodeone **root,char name[], struct nodeone * NILONE){
    if (*root == NILONE) {
        return NILONE;
    } else{
        // if not in here 0
        // if in here 1

        struct nodeone **x = (root);

        while (*x != NILONE)
        {
            int val = strcmp(name,(*x)->name1);
            if (val<0) {
                x = &(*x)->left;
            }
            else if (val>0) {
                x = &(*x)->right;
            }
            else if(val==0){
                return *x;
            }
        }
        return NILONE;
    }
}

// Utility function to insert newly node in RedBlack tree
void addent(struct node **root, char name[], struct node * NIL)
{
    //if root is NIL make z as root
    if (*root == NIL)
    {
        // Allocate memory for new node
        struct node *z = malloc(sizeof(struct node));
        z->name = malloc(strlen(name) * sizeof(char)+1);  //printf("\nMALLOC node %s\n",name);
        strcpy(z->name ,name);
        z->left = z->right = z->parent = NIL;

        z->color = 'B';
        (*root) = z;

    }
    else
    {
        struct node *y = NIL;
        struct node *x = (*root);

        // Follow standard BST insert steps to first insert the node
        while (x != NIL)
        {
            int val = strcmp(name,x->name);
            y = x;
            if (val<0) {
                //printf("%s < %s\n", z->name, x->name);
                x = x->left;

            }
            else if (val>0) {
                //printf("%s > %s\n", z->name, x->name);
                x = x->right;

            }
            else if(val==0){
                return;    // ALREADY CONTAINS NAME
            }
        }

        // Allocate memory for new node
        struct node *z = malloc(sizeof(struct node));
        z->name = malloc(strlen(name) * sizeof(char)+1);  //printf("\nMALLOC node %s\n",name);
        strcpy(z->name ,name);
        z->left = z->right = z->parent = NIL;

        z->parent = y;

        if(y!=NIL) {
            if (strcmp(z->name, y->name) > 0)
                y->right = z;
            else
                y->left = z;
        }
        z->color = 'R';

        // call insertFixUp to fix reb-black tree's property if it
        // is voilated due to insertion.
        insertFixUp(root,z, NIL);

    }
}

void deleteTree(struct node** node, struct node * NIL)
{
    if ((*node) == NIL || ((*node)->color!='R' && (*node)->color!='B')) return;

    /* first delete both subtrees */
    deleteTree(&(*node)->left, NIL);
    deleteTree(&(*node)->right, NIL);

    /* then delete the node */
    free((*node)->name);
    free(*node);
}

void createrel(struct nodeone **rootrels,char name1[],char name2[], struct node * NIL, struct nodeone * NILONE){

    //if root is NILONE make z as root
    if (*rootrels == NILONE)
    {
        struct nodeone *z = malloc(sizeof(struct nodeone));
        z->name1 = malloc(strlen(name1) * sizeof(char)+1); //printf("\nMALLOC nodeone\n");
        strcpy(z->name1 ,name1);
        z->left = z->right = z->parent = NILONE;
        z->root = NIL;
        z->numrel =1;

        z->color = 'B';
        (*rootrels) = z;
        addent(&(*rootrels)->root,name2, NIL);
    }
    else
    {
        struct nodeone *y = NILONE;
        struct nodeone *x = (*rootrels);

        // Follow standard BST insert steps to first insert the node
        while (x != NILONE)
        {
            y = x;
            int val = strcmp(name1,x->name1);
            if (val<0) {
                //printf("%s <one %s\n", z->name1, x->name1);
                x = x->left;
            }
            else if (val>0) {
                // printf("%s >one %s\n", z->name1, x->name1);
                x = x->right;
            }
            else if(val==0){
                if(contains(&(x->root),name2, NIL)) {// CHECK IF NAME2 DIFFERENT INSIDE ADDENT
                    return;    // ALREADY CONTAINS NAME2, NOTHING TO FIX
                }else{
                    addent(&(x->root),name2, NIL);
                    x->numrel = x->numrel + 1;
                    return;
                }
            }
        }

        struct nodeone *z = malloc(sizeof(struct nodeone));
        z->name1 = malloc(strlen(name1) * sizeof(char)+1); //printf("\nMALLOC nodeone\n");
        strcpy(z->name1 ,name1);
        z->left = z->right = z->parent = NILONE;
        z->root = NIL;
        z->numrel =1;

        z->parent = y;
        if(y!=NILONE) {
            if (strcmp(z->name1, y->name1) > 0)
                y->right = z;
            else
                y->left = z;
        }
        z->color = 'R';

        addent(&(z->root),name2, NIL);

        // call insertFixUp to fix reb-black tree's property if it
        // is voilated due to insertion.
        insertFixUpRel(rootrels,z, NILONE);
    }
}
// A utility function to traverse Red-Black tree in inorder fashion
void inorder(struct node *root, struct node * NIL)
{
    if (root == NIL || root->color<0)
        return;

    inorder(root->left, NIL);
    fputs(root->name,stdout);
    fputs(" ",stdout);
    inorder(root->right, NIL);

}
// A utility function to traverse Red-Black tree in inorder fashion
void inorderOne(struct nodeone *root, struct node * NIL, struct nodeone * NILONE)
{
    if (root == NILONE)
        return;


    if(root->left!=NILONE && root->left->color!='B' && root->left->color!='R') {
//        printf("\n\nError\n\n");
        return;
    }

    inorderOne(root->left, NIL, NILONE);

    printf("%s %d with ", root->name1, root->numrel);
    inorder(root->root, NIL); //MAYBE USEFUL TO PRINT NAME2
    printf("\n");
    inorderOne(root->right, NIL, NILONE);

}
// A utility function to traverse Red-Black tree in inorder fashion
void inorderrel(struct noderel *rootrel, struct node * NIL, struct nodeone * NILONE, struct noderel * NILREL)
{
    if (rootrel == NILREL)
        return;

    printf("\nrel %s:", rootrel->namerel);
    inorderOne(rootrel->names, NIL, NILONE);
    inorderrel(rootrel->next, NIL, NILONE, NILREL);

}



void deleteTreeOne(struct nodeone** node, struct nodeone * NILONE, struct node * NIL)
{
    if ((*node) == NILONE || ((*node)->color!='R' && (*node)->color!='B')) return;

    /* first delete both subtrees */
    deleteTreeOne(&(*node)->left, NILONE,NIL);
    deleteTreeOne(&(*node)->right, NILONE,NIL);

    /* then delete the node */
    free((*node)->name1);
    deleteTree(&(*node)->root,NIL);
    free(*node);
}

void addrel(struct noderel **rootrel,char rel[],char name1[],char name2[], struct node * NIL, struct nodeone * NILONE, struct noderel * NILREL){

    //z->names->left = z->names->right = z->names->parent = NIL;

    struct noderel **x = rootrel;

    if (*rootrel == NILREL || strcmp(rel,(*x)->namerel)<0)
    {

        struct noderel *z = malloc(sizeof(struct noderel));
        z->namerel = malloc(strlen(rel) * sizeof(char)+1); //printf("\nMALLOC noderel\n");
        strcpy(z->namerel ,rel);
        z->next = NILREL;
        z->names = NILONE;
        z->next = *x;
        (*rootrel) = z;
        createrel(&(*rootrel)->names, name1, name2, NIL, NILONE);
        return;
    }
    struct noderel **y = x;
    while ((*y)->next != NILREL && strcmp(rel,(*y)->next->namerel)>0)
    {
        y = &(*y)->next;
    }
    if(strcmp(rel,(*y)->namerel)==0){
        createrel(&(*y)->names, name1, name2, NIL, NILONE);
        return;

    } else if( (*y)->next!= NILREL && strcmp(rel,(*y)->next->namerel)==0){ // TODO INUTILE ROBA SPRECA TEMPO MA VA
        createrel(&((*y)->next)->names, name1, name2, NIL, NILONE);
        return;
    }
    else{

        struct noderel *z = malloc(sizeof(struct noderel));
        z->namerel = malloc(strlen(rel) * sizeof(char)+1); //printf("\nMALLOC noderel\n");
        strcpy(z->namerel ,rel);
        z->next = NILREL;
        z->names = NILONE;
        z->next = (*y)->next;
        (*y)->next = z;
        createrel(&(z->names), name1, name2, NIL, NILONE);
    }

    //inorderOne((*rootrel)->names);

}


struct node* min(struct node *x, struct node * NIL)

{          while (x->left!=NIL)

    {          x = x->left;

    } return x;

}

struct node* successor(struct node *x, struct node * NIL)

{          struct node *y;

    if(x==NIL) return NIL;

    if (x->right!=NIL)

    {          return min(x->right, NIL);

    }          y = x->parent;

    while (y!=NIL && x == y->right)

    {          x = y;

        y = y->parent;

    }return y;

}


void deleteFixup(struct node **root, struct node *x, struct node * NIL) {
    struct node *w = NIL;

    if(x->color == 'R' || x->parent == NIL){
        x->color = 'B';
    }
    else if(x == x->parent->left){
        w = x->parent->right;

        if(w->color == 'R'){
            w->color = 'B';
            x->parent->color = 'R';
            leftRotate(root,x->parent, NIL);
            w = x->parent->right;
        }
        if(w->left->color == 'B' && w->right->color == 'B'){
            w->color = 'R';
            deleteFixup(root,x->parent, NIL);
        }
        else{
            if(w->right->color == 'B') {
                w->left->color = 'B';
                w->color = 'R';
                rightRotate(root, w, NIL);
                w = x->parent->right;
            }
            w->color = x->parent->color;
            x->parent->color = 'B';
            w->right->color = 'B';
            leftRotate(root, x->parent, NIL);
        }
    }
    else{
        w = x->parent->left;

        if(w->color == 'R'){
            w->color = 'B';
            x->parent->color = 'R';
            rightRotate(root,x->parent, NIL);
            w = x->parent->left;
        }
        if(w->right->color == 'B' && w->left->color == 'B'){
            w->color = 'R';
            deleteFixup(root,x->parent, NIL);
        }
        else{
            if(w->left->color == 'B') {
                w->right->color = 'B';
                w->color = 'R';
                leftRotate(root, w, NIL);
                w = x->parent->left;
            }
            w->color = x->parent->color;
            x->parent->color = 'B';
            w->left->color = 'B';
            rightRotate(root, x->parent, NIL);
        }
    }
}

node* deleteNode(struct node **root, struct node **node, struct node * NIL) { // NOTA Y DA ELIMINARE, X CON CUI LO SOSTITUIAMO
    struct node * x = NIL, * y = NIL;
    int flag = 0;

    if ((*node) == NIL) {
        return *root;
    }else {
        if ((*root)->left == NIL && (*root)->right == NIL && (*root)->name == (*node)->name) {
            free(*root);
            *root = NIL;
//            printf("\nTHIS FREED ROOTONE");
            //inorderOne(*root);
            return NIL;
        }

        if (((*node)->left) == NIL || ((*node)->right) == NIL) {
            y = (*node);
        } else {
            y = successor((*node), NIL);
            flag=1;
        }

        if (y->left != NIL) {
            x = y->left;
        } else {
            x = y->right;
        }

        x->parent = y->parent;

        if (y->parent == NIL) {
            root = &x;
        } else {
            //struct node * temp = &(**node);
            if (y == y->parent->left)
            {
                y->parent->left = x;
            } else {
                y->parent->right = x;
            }

            //*node = temp;
        }

        if (flag==1) { // se il nodo estratto y è il successore di *node, il contenuto dell oggetto *node
            // viene sostituito  con quello di y
            (*node)->name = y->name;
        }

        if (y->color == 'B') {
            deleteFixup(root, x, NIL);
        }
        // NO FREE(Y->NAME) OR NOT
        if(y!=NIL) {
            free(y);
        }

    }
//        printf("\nAFTER\n");
//    inorder(*root);
    return *root;
}

struct nodeone* minOne(struct nodeone *x, struct nodeone * NILONE)

{
    while (x->left!=NILONE){
        x = x->left;
    }
    return x;

}

struct nodeone* successorOne(struct nodeone *x, struct nodeone * NILONE)

{          struct nodeone *y;

    if(x==NILONE) return NILONE;

    if (x->right!=NILONE)

    {          return minOne(x->right, NILONE);

    }
    y = x->parent;

    while (y!=NILONE && x == y->right)

    {          x = y;

        y = y->parent;

    }return y;

}


int searchMax(struct nodeone *x, struct nodeone * NILONE)
{
    int n=0;
    struct nodeone * y = minOne(x,NILONE);

    while (y!=NILONE){
        if(y->numrel > n){
            n = y->numrel;
        }
        y = successorOne(y,NILONE);

    }
    return n;

}

void deleteFixupone(struct nodeone **root, struct nodeone *x, struct nodeone * NILONE)
{
    struct nodeone *w = NILONE;

    if(x->color == 'R' || x->parent == NILONE){
        x->color = 'B';
    }
    else if(x == x->parent->left){
        w = x->parent->right;

        if(w->color == 'R'){
            w->color = 'B';
            x->parent->color = 'R';
            leftRotateRel(root,x->parent, NILONE);
            w = x->parent->right;
        }
        if(w->left->color == 'B' && w->right->color == 'B'){
            w->color = 'R';
            deleteFixupone(root,x->parent, NILONE);
        }
        else{
            if(w->right->color == 'B') {
                w->left->color = 'B';
                w->color = 'R';
                rightRotateRel(root, w, NILONE);
                w = x->parent->right;
            }
            w->color = x->parent->color;
            x->parent->color = 'B';
            w->right->color = 'B';
            leftRotateRel(root, x->parent, NILONE);
        }
    }
    else{
        w = x->parent->left;

        if(w->color == 'R'){
            w->color = 'B';
            x->parent->color = 'R';
            rightRotateRel(root,x->parent, NILONE);
            w = x->parent->left;
        }
        if(w->right->color == 'B' && w->left->color == 'B'){
            w->color = 'R';
            deleteFixupone(root,x->parent, NILONE);
        }
        else{
            if(w->left->color == 'B') {
                w->right->color = 'B';
                w->color = 'R';
                leftRotateRel(root, w, NILONE);
                w = x->parent->left;
            }
            w->color = x->parent->color;
            x->parent->color = 'B';
            w->left->color = 'B';
            rightRotateRel(root, x->parent, NILONE);
        }
    }
}



nodeone* deleteNodeone(struct nodeone **root, struct nodeone **node, struct nodeone * NILONE) {
    struct nodeone * x = NILONE, * y = NILONE;
    int flag =0;

    if ((*node) == NILONE) {
        return *root;
    }else {
        if ((*root)->left == NILONE && (*root)->right == NILONE && (*root)->name1 == (*node)->name1) {
            free(*root);
            *root = NILONE;
//            printf("\nTHIS FREED ROOTONE");
            //inorderOne(*root);
            return NILONE;
        }

        if (((*node)->left) == NILONE || ((*node)->right) == NILONE) {
            y = (*node);
        } else {
            y = successorOne((*node), NILONE);
            flag=1;
        }

        if (y->left != NILONE) {
            x = y->left;
        } else {
            x = y->right;
        }

        x->parent = y->parent;

        if (y->parent == NILONE) {
            root = &x;
        } else {
            if (y == y->parent->left)
            {
                y->parent->left = x;
            } else {
                y->parent->right = x;

            }
        }
        if (flag==1) {
            (*node)->name1 = y->name1;
            (*node)->numrel = y->numrel;
            (*node)->root = y->root;
        }

        if (y->color == 'B') {
            deleteFixupone(root, x, NILONE);
        }

    }
//        printf("\nAFTER\n");
//    inorder(*root);
    return *root;
}




// REL LIST TO FIND REL
void delrel(struct node **root, struct noderel **rootrel, char *rel, char *name1, char *name2, struct node * NIL, struct nodeone * NILONE, struct noderel * NILREL) {
    struct noderel **x = (rootrel);

    while (*x != NILREL && strcmp(rel, (*x)->namerel) != 0) {
        x = &(*x)->next;
    }
    if ((*x) == NILREL || (*x)->names == NILONE) {
        return;
    } else {
        //
        if (*root == NIL)
        {
            return;
        }
        else {
            struct nodeone *y = NILONE;
            y = findOne(&(*x)->names,name1, NILONE);
            if (y!=NILONE)
            {  // FOUND
                int flag =0;
                struct node *z = NIL;
                struct nodeone * r2 = (*x)->names;
                z = find(&((y)->root),name2, NIL);

                if(z!=NIL)
                    (y)->numrel = (y)->numrel -1;

                (y)->root = deleteNode(&((y)->root),&z, NIL);
                z=NIL;

                if((y)->root== NIL && r2==y && r2->left==NILONE && r2->right==NILONE) {
                    flag = 1;
                }

                if((y)->numrel==0){   // REMOVE NODEONE

                    (y)->root=NIL;
                    (*x)->names = deleteNodeone(&(*x)->names,&y, NILONE);
                    y=NILONE;
                }
                if(flag==1)
                    (*x)->names = NILONE;
            }
        }
        //
    }
}



void findBest(struct nodeone** rootone, struct node * NIL, struct nodeone * NILONE){
    struct nodeone *it = NILONE;
    struct node * rootbest = NIL;
    int n = 0;

    it=minOne(*rootone, NILONE);

    while (it!=NILONE){

        if(rootbest==NIL){
            addent(&rootbest,it->name1, NIL);
            n= it->numrel;
        } else{
            if(it->numrel==n){
                addent(&rootbest,it->name1, NIL);
            } else if (it->numrel > n){

                deleteTree(&rootbest, NIL);
                //free(rootbest); TODO CHECK IF I HAVE TO RESTORE IT (INVALID FREE VALGRIND)
                rootbest=NIL;

                addent(&rootbest,it->name1, NIL);
                n= it->numrel;
            }
        }
        it = successorOne(it, NILONE);
    }

    inorder(rootbest, NIL);
    printf("%d", n);

    deleteTree(&rootbest,NIL);
}

void report(struct noderel *rootrel, struct node * NIL, struct nodeone * NILONE, struct noderel * NILREL)
{
    if (rootrel == NILREL) {
        fputs("none",stdout);
        return;
    }
    if(rootrel->names != NILONE) {
        fputs(rootrel->namerel,stdout);
        fputs(" ",stdout);
        findBest(&(rootrel->names), NIL, NILONE);
        fputs(";",stdout);
        //inorderOne(rootrel->names); //NAMES1 PER LA RELAZIONE

        if(rootrel->next==NILREL) {
            return;
        } else{
            fputs(" ",stdout);
        }
    }
    if(rootrel->next!=NILREL) {
        report(rootrel->next, NIL, NILONE, NILREL);
    }else{
        return;
    }

}
void delent(struct node **root, struct noderel **rootrel, char *name, struct node * NIL, struct nodeone * NILONE, struct noderel * NILREL) {
    struct noderel **x = rootrel;
    struct nodeone *y = NILONE;
    struct node *w = NIL;
    struct nodeone **rootone = &NILONE;
    struct node **q = (root);

    while ((*x) != NILREL) { // FOR EVERY REL IN ROOTREL DO THIS
        if ((*x)->names != NILONE) {
            rootone = &((*x)->names);

            if (*rootone != NILONE) { // TODO CHECK SE HA SENSO PRIMA != POI ==
                // CHECK IF THERE IS NAME IN NAME1 (FREES EVERYTHING) OR IN NAME2 (FREES JUST THIS)
                // AFTER EVERYTHING FIX THINGS
                if (*rootone == NILONE)
                    return;

                y = minOne(*rootone, NILONE);
                int flag =0;
                while (y!=NILONE) {
                    struct nodeone * r = successorOne(y, NILONE);
                    if(strcmp((y)->name1,name)==0){
//                        printf("\n1\n");
                        //DEL ALL, FREE EVERY NAME2
                        deleteTree(&(y)->root,NIL); // FUNZIONA!?
                        (y)->root=NIL;

                        if(*rootone==y && (*rootone)->left==NILONE && (*rootone)->right ==NILONE){
                            flag=2;
//                            printf("FLAG 2\n");
                        }

                        ((*x)->names) = deleteNodeone(rootone,&y,NILONE);
                        if(flag==2) {
                            (*x)->names = NILONE;
                        }
                        char * namer = r->name1;
                        if(namer!=NILONE->name1) {
                            y = findOne(&(*x)->names, namer, NILONE);
                        }else{
                            y=NILONE;
                        }
                        flag =1;

                    }else if ((y)->root!=NIL) {

                        //DEL JUST THIS
                        w = find(&(y)->root, name, NIL);
                        if(w!=NIL) {

                            (y)->root = deleteNode(&(y)->root, &w, NIL); //FUNZIONA!?
                            w = NIL;
                            (y)->numrel = (y)->numrel - 1;

                            if ((y)->numrel == 0) {   // REMOVE NODEONE
                                (y)->root = NIL;
                                (*x)->names = deleteNodeone(&(*x)->names, &y, NILONE);
                                if (r != NILONE) {
                                    y = findOne(&(*x)->names, r->name1, NILONE);
                                } else {
                                    y = NILONE;
                                }
                                flag = 1;
                            }
                        }
                    }
                    /* printf("\ninorder %s, rel %s\n", y->name1, (*x)->namerel);
                          inorder(y->root);
                     printf("\n");*/
                    if(flag!=1)
                        y = successorOne(y, NILONE);
                    flag =0;
                    if(y==NILONE)
                        break;

                }
            }
            //if(n==2) TODO FIX
            //  (*x)->names = NIL;
        }
        if ((*x)->next != NILREL) {
            x = (&(*x)->next);
        } else {
            break;
        }
    }
    // DEL ENT FROM ROOT
    while (*q != NIL) {
        int val = strcmp(name, (*q)->name);
        if (val < 0) {
            //printf("%s < %s\n", z->name, x->name);
            q = &(*q)->left;

        } else if (val > 0) {
            //printf("%s > %s\n", z->name, x->name);
            q = &(*q)->right;

        } else if (val == 0) {
//            printf("\ndelent %s\n",name);
//
//            if(*root==NIL)
//                printf("\nRoot before NIL\n");
////
//            printf("\nBEFORE DEL ROOT ");
//            inorder(*root,NIL);
//
//            printf("\nDELETING NODE\n");

            *root = deleteNode(root, q,NIL);
//            inorder(*root);
//            inorderrel(*rootrel, NIL, NILONE, NILREL);

//            printf("\nNODE DELETED\n");
//            if(*root==NIL)
//                printf("\nRoot NIL\n");

            return;
        }
    }

}

int main()
{

    // TODO REMOVE IF LINUX
//    freopen("D:/PoliCartella/API/api/batch6.2.in","r",stdin);

    node * NIL = malloc(sizeof(node));
    NIL->left = NIL;
    NIL->right = NIL;
    NIL->parent = NIL;
    NIL->color ='B';

    nodeone * NILONE = malloc(sizeof(nodeone));
    NILONE->left = NILONE;
    NILONE->right = NILONE;
    NILONE->parent = NILONE;
    NILONE->color ='B';
    NILONE->root = NIL;
    NILONE->numrel = 0;

    noderel * NILREL = malloc(sizeof(noderel));
    NILREL->next = NILREL;
    NILREL->names = NILONE;

    struct node *root = NIL;
    struct noderel *rootrel = NILREL;

    // GETS INPUT AND DOES THINGS
    char cmd[7];
    char arg1[BUFFLENGHT];
    char arg2[BUFFLENGHT]="";
    char arg3[BUFFLENGHT]="";
    memset(arg1,0,BUFFLENGHT);
    memset(arg2,0,BUFFLENGHT);
    memset(arg3,0,BUFFLENGHT);

    int flag=0;
//
//    printf("\nSIZE OF NODE %d\n", sizeof(struct node));
//    printf("SIZE OF NODEONE %d", sizeof(struct nodeone));
//    printf("\nSIZE OF NODEREL %d\n", sizeof(struct noderel));

    // while (scanf("%s",cmd) == 1){
    while (scanf("%s",cmd) == 1 && strcmp(cmd,"end")!=0){


        if(strcmp(cmd,"addent")==0){
            scanf("%s",arg1);
            //if(contains(&root,arg1)==0) {

//            printf("adding ent : %s \n",arg1);

            addent(&root, arg1, NIL);


        } else if(strcmp(cmd,"addrel")==0) {
            scanf("%s", arg1); // ORIG
            scanf("%s", arg2); // DEST
            scanf("%s", arg3); // REL

            if (contains(&root, arg1, NIL) && contains(&root, arg2, NIL)) {

                addrel(&rootrel, arg3, arg2, arg1,NIL, NILONE, NILREL);

            }
        } else if(strcmp(cmd,"delent")==0){
            scanf("%s",arg1);

            if(contains(&root,arg1, NIL)){ // CHECK IF ENTITY IS IN ROOT ELSE DOES NOTHING

                delent(&root, &rootrel, arg1,NIL, NILONE, NILREL);

            }
        } else if(strcmp(cmd,"delrel")==0){
            scanf("%s",arg1); // ORIG
            scanf("%s",arg2); // DEST
            scanf("%s",arg3); // REL

            if (contains(&root, arg1, NIL) && contains(&root, arg2, NIL)) {

                delrel(&root, &rootrel, arg3, arg2, arg1,NIL, NILONE, NILREL);

            }
        } if(strcmp(cmd,"report")==0){

            if(flag==1){
                printf("\n");
            }
            report(rootrel,NIL, NILONE, NILREL);

            flag=1;
        }
    }


    // TODO REMOVE IF LINUX
//    fclose (stdin);

    return 0;
}
