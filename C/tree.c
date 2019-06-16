#include <stdio.h>
#include <stdlib.h>

// 노드의 구조
struct TreeNode {
	int key;
	int left;
	int right;
};

void menu();
void insert_node(int key) ;
void search_node(int key) ;
void delete_node(int key) ;

FILE *fp;

// 이진 탐색 트리 프로그램
void main(){
    char command;
 	int  key;

	// 파일을 읽기/쓰기 모드로 연다.(w+ 모드는 기존 내용을 지워버리므로 반드시 r+모드로..)
	// 그러나 r+모드는 화일이 존재하지 않을 경우 화일을 만들지 못하므로 다음과 같이 만들어준다.
	if( (fp = fopen("tree.txt", "r+")) == NULL ){
		fp = fopen("tree.txt", "w+");
//		fprintf(fp, "%2d %2d %2d", -1,-1,-1); // 초기화
		fprintf(fp, "%2d %2d %2d\n", -1,-1,-1); // 초기화
			}

    do{
		menu();
       	command = getchar();

		switch(command){
		case 'i':  //삽입
			printf("음수를 입력하면 종료\n");
			while(1) {
				printf("삽입키값:");
				scanf("%d", &key);
				if(key <0) break;
				insert_node(key);
			}
			break;
		case 's':  //삽입
			printf("음수를 입력하면 종료\n");
			while(1) {
				printf("탐색키값:");
				scanf("%d", &key);
				if(key <0) break;
				search_node(key);
			}
			break;
		case 'd':  //삽입
			printf("음수를 입력하면 종료\n");
			while(1) {
				printf("삭제키값:");
				scanf("%d", &key);
				if(key <0) break;
				delete_node(key);
			}
			break;
		}
		fflush(stdin);

    } while(command != 'q');
}

void insert_node(int key){
    int current_adr, parent_adr, new_adr; // current는 현재 노드, parent는 부모 노드
	struct TreeNode parent, current= {-1,-1,-1};
	current_adr=parent_adr=0;
	parent.key = NULL;

	//다음의 while문은 새로운 노드가 삽입될 부모노드를 찾기 위함이다.
	while (1) {
//		fseek(fp, 8*current_adr, SEEK_SET);    //8 = 키 2자리 + 공백1 + 왼쪽 포인터 2 + 공백1 + 오른쪽 2
		fseek(fp, 10*current_adr, SEEK_SET);   //10 = 키 2자리 + 공백1 + 왼쪽 포인터 2 + 공백1 + 오른쪽 2 + CR+LF
		fscanf(fp, "%2d %2d %2d", &current.key, &current.left, &current.right);

	if( key == current.key) {
		printf("Duplicated Key!\n");
		return; //이미 존재하는 키값이면 종료
	}
    if( key < current.key &&  current.left > 0) current_adr = current.left;
	else if( key > current.key &&  current.right > 0) current_adr = current.right;
	else break;   //이 것은 leaf노드를 만났단 의미!
    }

	//위에서 찾은 노드를 새로운 노드의 부모 노드로 만든다. 그리고 부모 노드와 링크 연결
	parent_adr = current_adr;
	parent = current;

	if( parent.key != -1 )  //부모키값이 -1이라면 아무것도 없는 초기 상태임
	{
		fseek(fp, 0, SEEK_END);
		new_adr = ftell(fp);   //화일의 맨끝에 삽입하고 이 주소를 부모노드에 넘긴다
//		fprintf(fp, "%02d %2d %2d", key, -1, -1);
		fprintf(fp, "%02d %2d %2d\n", key, -1, -1);

		if( key < parent.key ) {
//			parent.left = new_adr/8;
//		    fseek(fp, 8*parent_adr+3, SEEK_SET);
			parent.left = new_adr/10;
		    fseek(fp, 10*parent_adr+3, SEEK_SET);   //3 = 키 2자리 + 공백 1자리
			fprintf(fp, "%02d", parent.left);
		}
		else {
//			parent.right = new_adr/8;
//			fseek(fp, 8*parent_adr+6, SEEK_SET);
			parent.right = new_adr/10;
			fseek(fp, 10*parent_adr+6, SEEK_SET);  ;   //6 = 키 2자리 + 공백 1자리 + 왼쪽자식 2자리 + 공백 1자리
			fprintf(fp, "%02d", parent.right);
		}
	}
	else {
		 fseek(fp, 0, SEEK_SET);//	     // 최초의 루트 삽입
//	     fprintf(fp, "%02d %2d %2d", key,-1,-1); // 최초의 루트 삽입
	     fprintf(fp, "%02d %2d %2d\n", key,-1,-1); // 최초의 루트 삽입
		 printf("root created!\n");

	}
}
void search_node(int key){
    int current_adr; // current는 현재 노드, parent는 부모 노드
	struct TreeNode parent, current= {-1,-1,-1};
	current_adr=0;
	while (1) {
//		fseek(fp, 8*current_adr, SEEK_SET);    //8 = 키 2자리 + 공백1 + 왼쪽 포인터 2 + 공백1 + 오른쪽 2
		fseek(fp, 10*current_adr, SEEK_SET);   //10 = 키 2자리 + 공백1 + 왼쪽 포인터 2 + 공백1 + 오른쪽 2 + CR+LF
		fscanf(fp, "%2d %2d %2d", &current.key, &current.left, &current.right);

	  if( key == current.key) {
		  printf("%d : Success!\n",  current.key);
		  return;
	  }
		  printf("%d -> ",  current.key);
      if( key < current.key &&  current.left > 0) current_adr = current.left;
		else if( key > current.key &&  current.right > 0) current_adr = current.right;
		else {
		  printf("%d : Failed!\n",  key);
			break;
		}

    }


}
void delete_node(int key){
    int current_adr, parent_adr, new_adr, succ_adr, succ_parent_adr, exist; // current는 현재 노드, parent는 부모 노드
	char right_left; //부모의 왼쪽자식인지 오른쪽자식인지를 나타내는 변수
	struct TreeNode parent, current= {-1,-1,-1};
	struct TreeNode succ, succ_parent= {-1,-1,-1};	 //중위순회를 위한 변수
	current_adr=parent_adr=0;
	parent.key = NULL;

	//다음의 while문은 삭제될 노드와 그의 부모노드를 찾기 위함이다.
	while (1) {
//		fseek(fp, 8*current_adr, SEEK_SET);    //8 = 키 2자리 + 공백1 + 왼쪽 포인터 2 + 공백1 + 오른쪽 2
		fseek(fp, 10*current_adr, SEEK_SET);   //10 = 키 2자리 + 공백1 + 왼쪽 포인터 2 + 공백1 + 오른쪽 2 + CR+LF
		fscanf(fp, "%2d %2d %2d", &current.key, &current.left, &current.right);

	  if( key == current.key) {
		  exist = 1;//이미 존재하는 키값이면 성공표시
		  break;
	  }
      if( key < current.key &&  current.left > 0) {
		  parent_adr= current_adr;
		  current_adr = current.left;
		  right_left='L';
	  }
	  else if( key > current.key &&  current.right > 0) {
	 		parent_adr= current_adr;
			current_adr = current.right;
		  right_left='R';
	  }
	  else {
			exist = 0;
			break;   //이 것은 leaf노드를 만났단 의미!
	  }

   }

if (exist==0) {
	printf("Not Found!\n");
	return;
}

		fseek(fp, 10*current_adr, SEEK_SET);
		fscanf(fp, "%2d %2d %2d", &current.key, &current.left, &current.right);


//리프노드이면 리프노드의 키값을 -1로 하고 부모노드의 링크를 -1로 해줌
	if ( current.left==-1 && current.right==-1) {
			fseek(fp, 10*current_adr, SEEK_SET);
			fprintf(fp, "%02d %2d %2d\n", -1,-1,-1);  //삭제노드의 값을 -1로 채움
			//이 노드가 바로 루트라면 더 이상 추가 작업이 필요 없음
		if(current_adr==0) {
			return;
		}
		if (right_left=='L') {
		    fseek(fp, 10*parent_adr+3, SEEK_SET);   //3 = 키 2자리 + 공백 1자리
			fprintf(fp, "%02d", -1);
		}
		else {
		    fseek(fp, 10*parent_adr+6, SEEK_SET);   //3 = 키 2자리 + 공백 1자리
			fprintf(fp, "%02d", -1);
		}
		return;
	}
// 왼쪽자식만 있는 경우 왼쪽 자식을 부모노드에 연결해줌
	if ( current.left > 0 && current.right == -1) {
		//그런데 이것이 루트라면 왼쪽 자식을 끌어올리고 왼쪽자식노드는 (-1, -1, -1)로 채움
		if(current_adr==0) {
			fseek(fp, 10*current.left, SEEK_SET);
			fscanf(fp, "%2d %2d %2d", &succ.key, &succ.left, &succ.right);
			fseek(fp, 0, SEEK_SET);
			fprintf(fp, "%02d %2d %2d\n",  succ.key, succ.left, succ.right);  //삭제노드의 값을 -1로 채움
			fseek(fp, 10*current.left, SEEK_SET);
			fprintf(fp, "%02d %2d %2d\n", -1,-1,-1);  //삭제노드의 값을 -1로 채움
		}
		else {
			fseek(fp, 10*current_adr, SEEK_SET);
			fprintf(fp, "%02d %2d %2d\n", -1,-1,-1);  //삭제노드의 값을 -1로 채움
			if (right_left=='L') {
				fseek(fp, 10*parent_adr+3, SEEK_SET);   //3 = 키 2자리 + 공백 1자리
				fprintf(fp, "%02d", current.left);
			}
			else {
				fseek(fp, 10*parent_adr+6, SEEK_SET);   //3 = 키 2자리 + 공백 1자리
				fprintf(fp, "%02d", current.left);
			}
		}
		return;
	}
// 오른쪽자식만 있는 경우 오른쪽 자식을 부모노드에 연결해줌
	if ( current.left == -1 && current.right > 0) {
		//그런데 이것이 루트라면 오른쪽 자식을 끌어올리고 오른쪽 자식노드는 (-1, -1, -1)로 채움
		if(current_adr==0) {
			fseek(fp, 10*current.right, SEEK_SET);
			fscanf(fp, "%2d %2d %2d", &succ.key, &succ.left, &succ.right);
			fseek(fp, 0, SEEK_SET);
			fprintf(fp, "%02d %2d %2d\n",  succ.key, succ.left, succ.right);  //삭제노드의 값을 -1로 채움
			fseek(fp, 10*current.right, SEEK_SET);
			fprintf(fp, "%02d %2d %2d\n", -1,-1,-1);  //삭제노드의 값을 -1로 채움
		}
		else {

			fseek(fp, 10*current_adr, SEEK_SET);
			fprintf(fp, "%02d %2d %2d\n", -1,-1,-1);  //삭제노드의 값을 -1로 채움
			if (right_left=='L') {
				fseek(fp, 10*parent_adr+3, SEEK_SET);   //3 = 키 2자리 + 공백 1자리
				fprintf(fp, "%02d", current.right);
			}
			else {
				fseek(fp, 10*parent_adr+6, SEEK_SET);   //3 = 키 2자리 + 공백 1자리
				fprintf(fp, "%02d",current.right);
			}

		}
		return;
	}
// 그 외의 경우는 두개의 자식을 가지는 경우이다. 중위순회에 의해 다음 탐색노드(succ)를 찾는다
// 즉, 오른쪽 자손 중 왼쪽 자식을 가지지 않는 마지막 노드
succ_adr = current.right;
succ_parent_adr = current_adr;

	while (1) {
//		fseek(fp, 8*current_adr, SEEK_SET);
		fseek(fp, 10*succ_adr, SEEK_SET);
		fscanf(fp, "%2d %2d %2d", &succ.key, &succ.left, &succ.right);
		if (succ.left==-1) {
			break;
		}
		succ_parent_adr = succ_adr;
		succ_adr=succ.left;
	}

		fseek(fp, 10*current_adr, SEEK_SET);
		fprintf(fp, "%02d",succ.key);  //삭제노드의 값을 승계자(succ)값으로 바꿈

//승계노드가 삭제 노드의 직속 오른쪽자식인 경우(승계노드가 부모노드의 오른쪽 자식)
//그렇지 않은 경우로 분리(승계노드가 부모노드의 왼쪽 자식)

		if (succ_parent_adr == current_adr) {
			fseek(fp, 10*current_adr+6, SEEK_SET);
			fprintf(fp, "%02d",succ.right);
		}
		else {
		fseek(fp, 10*succ_parent_adr+3, SEEK_SET);
		fprintf(fp, "%02d",succ.right);  //승계 부모노드의 왼쪽자식을 을 승계노드의 오른쪽 자식으로 바꿈
		}

		fseek(fp, 10*succ_adr, SEEK_SET);
		fprintf(fp, "%02d %2d %2d\n", -1,-1,-1);  //승계노드가 있던 자리는  -1로 채워 삭제표시
}

void menu(){
   printf("**************\n");
   printf("i: 입력\n");
   printf("d: 삭제\n");
   printf("s: 탐색\n");
   printf("q: 종료\n");
   printf("**************\n");
}
