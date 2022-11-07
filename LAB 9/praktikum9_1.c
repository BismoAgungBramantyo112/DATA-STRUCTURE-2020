#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct tree {
  int id, score;
  char nama[255];
  struct tree * left, * right;
}* root = NULL;

struct tree * create_node(int id, const char * nama, int score) {
  struct tree * newNode = (struct tree * ) malloc(sizeof(struct tree));
  newNode -> id = id;
  newNode -> score = score;
  strcpy(newNode -> nama, nama);
  newNode -> left = newNode -> right = NULL;
  return newNode;
}
struct tree * add_data(struct tree * root, int id,
  const char * nama, int score, int tinggi) {
  if (tinggi < 3) {
    if (root == NULL) {
      printf("\n--- Add New Data Success ---\n");
      return create_node(id, nama, score);
    } else {
      while (tinggi < 3) {
        if (id < root -> id) {
          root -> left = add_data(root -> left, id, nama, score, tinggi + 1);
        } else {
          root -> right = add_data(root -> right, id, nama, score, tinggi + 1);
        }
        break;
      }
    }
  } else if (tinggi == 3) {
    printf("\n--- Maximum Tree Height is 3 ---");
  }

  return root;

}

struct tree * search(struct tree * root, int id) {
  if (root != NULL) {
    if (root -> id == id) {
      return root;
    } else {
      struct tree * temp;
      temp = search(root -> left, id);
      if (temp == NULL) {
        temp = search(root -> right, id);
      }
      return temp;
    }
  }
}

void update_data(struct tree * root, const char * namabaru, int newscore) {
  if (root != NULL) {
    root -> score = newscore;
    strcpy(root -> nama, namabaru);
  }
}

void preorder(struct tree * root) {
  if (root) {
    printf("\n- %d     %s   [  %d  ]\n", root -> id, root -> nama, root -> score);
    preorder(root -> left);
    preorder(root -> right);
  }
}

void inorder(struct tree * root) {

  if (root) {
    inorder(root -> left);
    printf("\n- %d     %s   [  %d  ]\n", root -> id, root -> nama, root -> score);
    inorder(root -> right);
  }
}

void postorder(struct tree * root) {

  if (root) {
    postorder(root -> left);
    postorder(root -> right);
    printf("\n- %d     %s   [  %d  ]\n", root -> id, root -> nama, root -> score);
  }
}
struct tree * successor(struct tree * root) {
  struct tree * temp = root;

  while (temp && temp -> right != NULL)
    temp = temp -> right;

  return temp;
}

struct tree * delete_successor(struct tree * root, int id){
if (root == NULL) {
  return root;
}
if (id < root -> id) {
  root -> left = delete_successor(root -> left, id);
} else if (id > root -> id) {
  root -> right = delete_successor(root -> right, id);
} else {

  if (root -> left == NULL) {
    struct tree * temp = root -> right;
    printf("X%d - %s  <%d> is deleted\n", root -> id, root -> nama, root -> score);
    free(root);

    return temp;
  } else if (root -> right == NULL) {
    struct tree * temp = root -> left;
    printf("X%d - %s  <%d> is deleted\n", root -> id, root -> nama, root -> score);
    free(root);
    return temp;
  } else {

    struct tree * temp = successor(root -> right);

    root -> id = temp -> id;

    root -> right = delete_successor(root -> right, temp -> id);

    printf("X%d - %s  <%d> is deleted\n", root -> id, root -> nama, root -> score);
  }

}
return root;
}

int main() {
  int tinggi = 0, choice, score,newscore, id,  id1;
  char nama[255], metode[255];
  while (1) {
    printf("\nSinging Extracuricular");
    printf("\n ***************\n");;
    printf("\n1. Add a new data");
    printf("\n2. Update a certain data");
    printf("\n3. InOrder, PreOrder, PostOrder by Member ID");
    printf("\n4. Delete a certain data");
    printf("\n5. Exit");
    printf("\n>> Input Choice: ");
    scanf("%d", & choice);
    printf("\n");
    if (choice == 1) {
      while (1) {
        printf("Input ID X[1-9][0-9]: X");
        scanf("%d", & id);
        printf("\n");
        if (id < 10 || id > 99) {
          printf("-- Member ID is not found ---\n");
        } else {
          while (1) {
            printf("Input member name: ");
            scanf(" %[^\n]", nama);
            if (strlen(nama) < 0 || strlen(nama) > 20) {
              printf("\n--- Name Doesn't Exist ---");
            } else {
              while (1) {
                printf("Input singing score [1-100]: ");
                scanf("%d", & score);
                printf("\n");
                if (score < 1 || score > 100) {
                  printf("-- total score doesn't exist ---");
                } else if (search(root, id) == NULL) {
                  root = add_data(root, id, nama, score, tinggi);
                  break;
                } else if (search(root, id) != NULL) {
                  printf("\n-- Add New Data Failed--");
                  printf("\nIntership Employee ID Is Already Exist\n");
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      }
    } else if (choice == 2) {
      if (root == NULL) {
        printf("\n--- There is no data in the tree ---");
      } else {
        while (1) {
          printf("Input member ID X[1-9][0-9]: X");
          scanf("%d", & id1);
          printf("\n");
          if (id1 < 10 || id1 > 99) {
            printf("-- Member ID is not found ---\n");
          } else if (search(root, id1) == NULL) {
            printf("\nIntership Employee Id Is Not Found\n");
            printf("Press enter to continue...\n");
          } else if (search(root, id1) != NULL) {
            printf("\nMember ID   : X%d\n", root -> id);
            printf("Member name : %s\n", root -> nama);
            printf("Singing Score    : %d\n", root -> score);
            while (1) {
              printf("\n");
              printf("Input member name: ");
              scanf(" %[^\n]", nama);
              printf("\n");
              if (strlen(nama) < 0 || strlen(nama) > 20) {
                printf("-- Name Doesn't Exist ---\n");
              } else {
                while (1) {
                  printf("Input singing score [1-100]: ");
                  scanf("%d", & newscore);
                  printf("\n");
                  if (newscore < 1 || newscore > 100) {
                    printf("-- Score Doesn't Exist ---\n");
                  } else {
                    struct tree *
                      var = search(root, id1);
                    update_data(var, nama, newscore);
                    printf("\n--Update Suscessfull--");
                    break;
                  }
                  break;
                }

                break;
              }
              break;
            }
          }
          break;

        }
      }
    } else if (choice == 3) {
      if (root == NULL) {
        printf("\n--- There is no data in the tree ---");
      } else {
        printf("\n\nPreorder :");
        preorder(root);
        printf("\n\nInorder :");
        inorder(root);
        printf("\n\nPostorder :");
        postorder(root);
      }
    } else if (choice == 4) {
      if (root == NULL) {
        printf("\n--- There is no data in the tree ---");
      } else {
        while (1) {
          printf("Input member ID X[1-9][0-9]: X");
          scanf("%d", & id);
          printf("\n");
          if (id < 10 || id > 99) {
            printf("-- ID doesn't exist ---\n\n");
          } else if (search(root, id) == NULL) {
            printf("--- Member ID is not found---\n\n");
          } else if (search(root, id) != NULL) {
            root = delete_successor(root, id);
            break;
          }
        }
      }
    } else if (choice == 5) {
      printf("--- Program End ---\n");
      exit:
        break;
    }
  }

  return 0;
}
