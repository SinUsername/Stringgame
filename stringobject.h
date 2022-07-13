#ifndef _STRINGOBJECT_H
#define _STRINGOBJECT_H

#include "strtext.h"

#define V 50

typedef void * types;

struct Object{
    //Posiciones en X y Y del objeto
    int positionX;
    int positionY;
    //caja de colision
    int boxTop;
    int boxDown;
    int boxLetf;
    int boxright;
    //Otros
    int ID;
    int range;
    f gravity;
    //Para el nombre del objeto
    public Name[V];

};

struct asset{
    
    int ID;
    int color;
    char name[V];
    char data[V];
    
};

struct newObject{
    
    int positionX;
    int positionY;
    f gravity;
    int boxTop;
    int boxDown;
    int boxLetf;
    int boxright;
    int ID;
    int range;
    int onX1;
    int onX2;
    int onY1;
    int onY2;
    public name[V];
    
};

struct Scene{
    //Limites de la esena
    int limitX;
    int limitX2;
    int limitY;
    int limitY2;

    int ID;
    public name[V];

    int Gravity;
    f ObjectInSceneGravity;
    int ObjectInSceneGravityDX;
    
    int color , blocks;

};

struct limit {

    int X;
    int Y;

};

struct texture {

    int ID;
    int mode;
    char name[V];
    char nameFile[V];
    char content[1024];

};

static void ReadAsset (char nombre[1024])
{
	
	char cat[1024] = ".asset";
	char nose[1024];

	FILE *file;

	strcpy(nose, nombre);

	strcat(nose, cat);

	file = fopen(nose, "r");

	if (file == NULL)
	{
		printf("StringLibrary: \" %s \" bad adress! ", nombre);
		return;
	}
    StringReadFileModeRB(nose);
}

static void fileAssets (const char nameAsset[V] , const char * data){
    
    char cat[1024] = ".asset";
	char nose[1024];

	FILE *file;

	strcpy(nose, nameAsset);

	strcat(nose, cat);

	file = fopen(nose, "w");

	if (file == NULL)
	{
		printf("StringLibrary: \" %s \" error no create asset'", nameAsset);
		return;
	}

	fprintf(file, "%s", data);
	fclose(file);
    
}

void StrAssetStart (struct asset * Asset){
    
    void * VoidID = NULL;
    
    if(Asset->ID == (int)VoidID){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error StrAssetStart();\n",Asset->name,Asset->ID);
        return;
    }
    else{
        
        fileAssets(Asset->name,Asset->data);
        StrAttributeText(Asset->color);
        //dataTextures(Texture->nameFile,Texture->nameFile);
        
    }
    
}

void StrAssetPaint (struct asset * Asset){
    
    void * VoidID = NULL;
    
    if(Asset->ID == (int)VoidID){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error StrAssetPaint();\n",Asset->name,Asset->ID);
        return;
    }
    
    else{
        
        ReadAsset(Asset->name);
        
    }
    
}

void StrAssetEnd (struct asset * Asset){
    
    void * VoidID = NULL;
    
    if(Asset->ID == (int)VoidID){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error StrAssetEnd();\n",Asset->name,Asset->ID);
        return;
    }
    else{
        
        StrAttributeText(7);
        
    }
    
}

void StrMoveOtherObject (struct newObject * OtherObject){
    
    void * VoidID = NULL;
    
    if(OtherObject->ID == (int)VoidID){
        
        printf("ID of Object type: newObject is null (Object Name: '%s' | Object ID: '%d') in function StrMoveOtherObject\n",OtherObject->name,OtherObject->ID);
        return;
    }
    else{
        
        if(OtherObject->onX1 == 1){
            
            OtherObject->positionX++;
            
        }
        else if (OtherObject->onX1 == 2){
            
            OtherObject->positionX--;
            
        }
        //position Y
        if(OtherObject->onY1 == 1){
            
            OtherObject->positionY++;
            
        }
        else if (OtherObject->onY1 == 2){
            
            OtherObject->positionY--;
            
        }
        else{
            
            return;
            
        }
        
    }
    
}

/*static void StringReadFileModeRB (const char *URL)
{
	FILE *lectura;
	char variable[1025];

	lectura = fopen(URL, "rb");

	if (lectura == NULL)
	{
		perror("StringLibrary ");
		printf("Directorio o Archivo: [\" ");
		printf("%s", URL);
		printf(". \"] \n");
	}
	else
	{
		while (feof(lectura) == 0)
		{
			fgets(variable, 1025, lectura);
			printf("%s", variable);
		}
	}
	fclose(lectura);
}*/

static void ReadTexture (char nombre[1024])
{
	char cat[1024] = ".tr";
	char nose[1024];

	FILE *file;

	strcpy(nose, nombre);

	strcat(nose, cat);

	file = fopen(nose, "r");

	if (file == NULL)
	{
		printf("StringLibrary: \" %s \" -> 'Inixistente' ", nombre);
		return;
	}
    StringReadFileModeRB(nose);
    
}

int StrPowInt (int number){
    
    int pow = number * number;
    
    return pow;
    
}

double StrPow (double number){
    
    double pow = number * number;
    
    return pow;
    
}

void StrUsingTexture (struct texture * Texture , const char * otherDraw){

    void * VoidID = NULL;
    void * Voidtext = NULL;

    if(Texture->ID == (int)VoidID){
        printf("ID Texture is void (Name Texture: '%s' and ID: %i) in fuction: StrUsingTexture();\n",Texture->name,Texture->ID);
        return;
    }
    else{

        if(otherDraw == Voidtext){

            return;

        }
        else{

             ReadTexture(Texture->nameFile);

        }

    }

}

void StrPrintTexture (struct texture * Texture){

    void * VoidID = NULL;

    if(Texture->ID == (int)VoidID){
        printf("ID Texture is void (Name Texture: '%s' and ID: %i) in fuction: StrPrintTexture();\n",Texture->name,Texture->ID);
        return;
    }

    if(Texture->mode == 0){//Leer mediante un archivo

        ReadTexture(Texture->nameFile);

    }
    else if (Texture->mode == 1){//Simplemente mostrar

        printf("%s",Texture->content);

    }
    else{

        printf("Mode is void , remenmer 0 is file and 1 simple print\n");
        return;

    }

}

static void fileTextures (const char nameTexture[V] , const char * contentTexture){

    char cat[1024] = ".tr";
	char nose[1024];

	FILE *file;

	strcpy(nose, nameTexture);

	strcat(nose, cat);

	file = fopen(nose, "w");

	if (file == NULL)
	{
		printf("StringLibrary: \" %s \" error no create texture'", nameTexture);
		return;
	}

	fprintf(file, "%s", contentTexture);
	printf("StringLibrary: save texture\n");
	fclose(file);

}

static void dataTextures (const char nameTexture[V] , const char * contentTexture , struct texture * data){

    char cat[1024] = ".dat";
	char nose[1024];

	FILE *file;

	strcpy(nose, nameTexture);

	strcat(nose, cat);

	file = fopen(nose, "w");

	if (file == NULL)
	{
		printf("StringLibrary: \" %s \" error no create texture'", nameTexture);
		return;
	}

	fprintf(file, "Name texture: %s\nID the texture: %d", contentTexture , data->ID);
	printf("StringLibrary: Se ha guardado\n");

}

void StrTextures (struct texture * Texture){

    void * nullID = NULL;

    if(Texture->ID == (int)nullID){
        printf("ID Texture is void (Name Texture: '%s' and ID: %i) in fuction: StrTexture();\n",Texture->name,Texture->ID);
        return;
    }
    else{

        fileTextures(Texture->nameFile,Texture->content);
        dataTextures(Texture->nameFile,Texture->nameFile,Texture);

    }

}

void StrScene (struct Scene * cene , struct Object * Object){

    void * VoidID = NULL;// NULL = 0

    if(cene->ID == (int)VoidID){
        printf("ID Scene is void (Name scene: '%s' | ID scene: '%d')\n",cene->name,cene->ID);
        getch();
        exit(1);
    }

    else{

        if(Object->positionX == cene->limitX){
            Object->positionX--;
        }
        if(Object->positionY == cene->limitY){
            Object->positionY--;
        }
        if(Object->positionX == cene->limitX2){
            Object->positionX++;
        }
        if(Object->positionY == cene->limitY2){
            Object->positionY++;
        }

    }

}

void StrShowSceneLimits(struct Scene * limitScene){

    printf("Scene's limit: Right'X': %d | Letf'X': %d \nDown'Y': %d | Top'Y': %d | Name: '%s' | ID: %d\n",limitScene->limitX,limitScene->limitX2,limitScene->limitY,limitScene->limitY2,limitScene->name,limitScene->ID);

}

void StrPaintAsset (int cand_assets , ...){

    int ini;
    char *paint_assets;
    va_list assets;

    va_start(assets,cand_assets);

    for(ini = 0; ini < cand_assets; ++ini){

        paint_assets = va_arg(assets,char*);
        printf("%s",paint_assets);

    }

    va_end(assets);

}

static void color (int Color , int Xx){
    
    int ini=0;
    
    if(Color == 0){//Azul (17)
        
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(out,17);
        
        
        while(ini != Xx){
            
            ini++;
            printf("#");
            
            if(ini == Xx){
                
                break;
                
            }
            
        }
        
    }
    
   if(Color == 1){//Verde
      
      HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(out,34);
        
        
        while(ini != Xx){
            
            ini++;
            printf("#");
            
            if(ini == Xx){
                
                break;
                
            }
            
        }
        
    }
    
    if(Color == 2){//Cyan o celeste
      
      HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(out,51);
        
        
        while(ini != Xx){
            
            ini++;
            printf("#");
            
            if(ini == Xx){
                
                break;
                
            }
            
        }
        
    }
    
    if(Color == 3){//Rojo
      
      HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(out,68);
        
        
        while(ini != Xx){
            
            ini++;
            printf("#");
            
            if(ini == Xx){
                
                break;
                
            }
            
        }
        
    }
    
    if(Color == 4){//Rosado
      
      HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(out,85);
        
        
        while(ini != Xx){
            
            ini++;
            printf("#");
            
            if(ini == Xx){
                
                break;
                
            }
            
        }
        
    }
    
    if(Color == 5){//Amarillo
      
      HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(out,102);
        
        
        while(ini != Xx){
            
            ini++;
            printf("#");
            
            if(ini == Xx){
                
                break;
                
            }
            
        }
        
    }
    
    if(Color == 6){//Blanco
      
      HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(out,119);
        
        
        while(ini != Xx){
            
            ini++;
            printf("#");
            
            if(ini == Xx){
                
                break;
                
            }
            
        }
        
    }
    
    if(Color == 7){//Gris
      
      HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(out,136);
        
        
        while(ini != Xx){
            
            ini++;
            printf("#");
            
            if(ini == Xx){
                
                break;
                
            }
            
        }
        
    }
    
    else{
        
        return;
        
    }
    
}

void StrSceneEnd (struct Scene * Esena){
    
    void * VoidID = NULL;
    
    if(Esena->ID == (int)VoidID){
        printf("ID Scene is void (Name scene: '%s') Function error StrSceneEnd();\n",Esena->name);
        getch();
        return;
    }
    
    HANDLE out;
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(out,7);
    
}

void StrSceneClrs (struct Scene * Esena){
    
    void * VoidID = NULL;
    
    if(Esena->ID == (int)VoidID){
        printf("ID Scene is void (Name scene: '%s') Function error StrSceneClrs();\n",Esena->name);
        getch();
        return;
    }
    
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD bufferSize, charsWritten;

    COORD topleft = {0, 0};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    bufferSize = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hConsole, TEXT(' '), bufferSize, topleft, &charsWritten);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, bufferSize, topleft, &charsWritten);
    SetConsoleCursorPosition(hConsole, topleft);
    
}

void StrSceneStart(struct Scene * Esena){
    
    void * VoidID = NULL;
    
    if(Esena->ID == (int)VoidID){
        printf("ID Scene is void (Name scene: '%s') Function error SceneStart\n",Esena->name);
        getch();
        return;
    }
    
    color(Esena->color,Esena->blocks);
    
}

void StrColorRGB(int R , int G , int B){

    if(R&&G&&B == 1){//Red , Green and blue on
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,7);
    	return;
    }
    if(R == 1){//Red on
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,4);
    	if(R&&G == 1){//Red and Green on / Yellow
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,6);
        	return;
        }
        if(R&&B == 1){//Red and Blue / Pink
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,5);
        	return;
        }
    	return;
    }
    if(G == 1){//Green on
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,2);
    	if(G&&R == 1){//Green and Red on / Yellow
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,6);
        	return;
        }
        if(G&&B == 1){//Green and Blue on / Cyan
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,11);
        	return;
        }
    	return;
    }
    if(B == 1){//Blue on
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,1);
    	if(B&&R == 1){//Blue and Red on / Pink
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,5);
        	return;
        }
        if(B&&G == 1){//Blue and Green on / Cyan
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,11);
        	return;
        }
    	return;
    }
    else{
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,0);
    }

}

void StrColorRGBA(int R , int G , int B , int A){
    
    if(A == 0){
    
    if(R&&G&&B == 1){//Red , Green and blue on
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,7);
    	return;
    }
    if(R == 1){//Red on
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,4);
    	if(R&&G == 1){//Red and Green on / Yellow
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,6);
        	return;
        }
        if(R&&B == 1){//Red and Blue / Pink
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,5);
        	return;
        }
    	return;
    }
    if(G == 1){//Green on
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,2);
    	if(G&&R == 1){//Green and Red on / Yellow
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,6);
        	return;
        }
        if(G&&B == 1){//Green and Blue on / Cyan
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,11);
        	return;
        }
    	return;
    }
    if(B == 1){//Blue on
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,1);
    	if(B&&R == 1){//Blue and Red on / Pink
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,5);
        	return;
        }
        if(B&&G == 1){//Blue and Green on / Cyan 
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,11);
        	return;
        }
    	return;
    }
    else{
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,0);
    }
  }
  //Colores mas intensos
  else if (A == 1){
    
    if(R&&G&&B == 1){//Red , Green and blue on
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,7);
    	return;
    }
    if(R == 1){//Red on
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,68);
    	if(R&&G == 1){//Red and Green on / Yellow
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,102);
        	return;
        }
        if(R&&B == 1){//Red and Blue / Pink
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,85);
        	return;
        }
    	return;
    }
    if(G == 1){//Green on
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,34);
    	if(G&&R == 1){//Green and Red on / Yellow
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,102);
        	return;
        }
        if(G&&B == 1){//Green and Blue on / Cyan
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,51);
        	return;
        }
    	return;
    }
    if(B == 1){//Blue on
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,17);
    	if(B&&R == 1){//Blue and Red on / Pink
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,85);
        	return;
        }
        if(B&&G == 1){//Blue and Green on / Cyan 
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,51);
        	return;
        }
    	return;
    }
    else{
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,0);
    }
    
  }
    
}

void StrShowObjectCoordinates (struct Object * Object){

    printf("Coordinates:'%s': X = %d | Y = %d | ID: %d\n",Object->Name,Object->positionX,Object->positionY,Object->ID);

}

void StrMoveObject (struct Object * posPlayer , const char * player , const char * key1 , const char * key2 , const char * key3 , const char * key4){

    char Keey;
    void * VoidID = NULL;// 0

    if(posPlayer->ID == (int)VoidID){

        printf("ID the object('%s') this incorrect , (ID value: %d) , functionError(StrMoveObject)\n",posPlayer->Name,posPlayer->ID);
        return;

    }

    HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = posPlayer->positionX;
	dwPos.Y = posPlayer->positionY;

	SetConsoleCursorPosition(hCon, dwPos);
	printf("%s\n",player);

	Keey = getch();

	//Movimiento en X
	if(Keey == key1){

	   if(key1 == NULL){
	       return;
	   }

	   posPlayer->positionX--;
	}

	if(Keey == key2){

	   if(key2 == NULL){
	       return;
	   }

	   posPlayer->positionX++;
	}

	if(Keey == key3){

	   if(key3 == NULL){
	       return;
	   }

	   posPlayer->positionY++;
	}

	if(Keey == key4){

	   if(key4 == NULL){
	       return;
	   }

	   posPlayer->positionY--;
	}

}

void StrlimitObject (struct Object * limitObject , int limitX1 , int limitX2, int limitY1 , int limitY2){

    void * VoidID = NULL;// 0

    if(limitObject->ID == (int)VoidID){

        printf("ID the object('%s') this incorrect , (ID value: %d) functionError(StrlimitObject)\n",limitObject->Name,limitObject->ID);
        return ;

    }

    //Posiciones en X de derecha a izquierda
    if(limitObject->positionX == limitX1){

        limitObject->positionX++;

    }

    if(limitObject->positionX == limitX2){

        limitObject->positionX--;

    }

    //Posiciones en Y de arriba a abajo
    if(limitObject->positionY == limitY1){

        limitObject->positionY++;

    }

    if(limitObject->positionY == limitY2){

        limitObject->positionY--;

    }


}

#endif
