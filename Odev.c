#include <stdio.h>
#include <math.h>


void menu();
void kayit(char[10][20],char[10][20],float[10],float[10],float[10]);
void bilgi();

int main() {
	int index,x,ort=0,a,o=0,sayac=0;
	float std;
	char ad[10][20];
	char soyad[10][20];
	float vize1[10];
	float vize2[10];
	float final[10];
	int note[10];
	char temp[10];
	char *name[10];
	char *lname[10];
	
	
	while(a!=6){
	menu();
	scanf("%d",&a);
	switch(a){
		case 1:
		
		kayit(ad,soyad,vize1,vize2,final);                                      //  Kayıt Fonksiyonu Çağrılır.          //
		for(int i = 0 ; i < 10 ; i++){
			    name[i]=ad[i];
			    lname[i]=soyad[i];
	}
		o=1;                                                                    //  Kayıt Eklendiğini Belirtmek İçin    //
			                                                                    //  "o" Değişkeni 1 Olarak Değiştirilir //
			break;
		
		case 2:
	    if(o==0){                                                               //  o Değişkeni Sayesinde       //
	        printf("Lutfen Once Kayit Ekleyiniz\n\n");                          //  Kayıt Yapılıp Yapılmadığı   //
	        break;                                                              //  Anlaşılır                   //
	    }
	    
		    printf("Ad\tSoyad\tVize1\tVize2\tFinal\tNotu\tHarf\tDurumu\n");
		    
		    for(int k=0 ; k<10 ; k++){
		        note[k]=round((vize1[k])*1/5 + (vize2[k])*3/10 + (final[k])*1/2); //    Not Hesaplanır //
		        
		        printf("%s\t",ad[k]);                                           //  Bu Kısımda  //
		        printf("%c.\t",soyad[k][0]);                                    //  Veriler     //
		        printf("%d\t",(int)vize1[k]);                                   //  Ekrana      //
		        printf("%d\t",(int)vize2[k]);                                   //  Yazdırılır  //
		        printf("%d\t",(int)final[k]);
		        printf("%d\t",note[k]);
		        
		        if(note[k]>89){                                                 //  Bu Kısımda  //
		            printf("AA\tGecti");                                        //  Notlara Göre//
		        }                                                               //  Harf Notu   //
		        else if((note[k]<90)&&(note[k]>84)){                            //  Kaldı-Geçti //
		            printf("BA\tGecti");                                        //  Durumu      //
		        }                                                               //  Ekrana      //
		        else if((note[k]<85)&&(note[k]>79)){                            //  Yazdırılır  //
		            printf("BB\tGecti");
		        }
		        else if((note[k]<80)&&(note[k]>74)){
		            printf("CB\tGecti");
		        }
		        else if((note[k]<75)&&(note[k]>69)){
		            printf("CC\tGecti");
		        }
		        else if((note[k]<70)&&(note[k]>64)){
		            printf("DC\tGecti");
		        }
		        else if((note[k]<65)&&(note[k]>59)){
		            printf("DD\tGecti");
		        }
		        else if((note[k]<60)&&(note[k]>49)){
		            printf("FD\tSartli Gecti");
		        }
		        else {
		            printf("FF\tKaldi");
		        }
		        printf("\n");
		    }
		    printf("\n");
		    
		 break;
		 
		 case 3:
		 if(o==0){                                                              //  o Değişkeni Sayesinde       //
	        printf("Lutfen Once Kayit Ekleyiniz\n\n");                          //  Kayıt Yapılıp Yapılmadığı   //
	        break;                                                              //  Anlaşılır                   //
	    }   
		 printf("\n\n---Sinif Basari Notlarini Hesapla---\n");
		 printf("Ad\tSoyad\tNotu\n");
		 for(int n=0 ; n<10 ; n++){
		     
		     note[n]=round((vize1[n])*1/5 + (vize2[n])*3/10 + (final[n])*1/2);  //  Not Hesaplanır //
		     printf("%s\t",ad[n]);
		     printf("%c.\t",soyad[n][0]);
		     printf("%d\t",note[n]);
		     printf("\n");
		 }
		 printf("\n");
		 break;
		 
		 case 4:
		 if(o==0){                                                              //  o Değişkeni Sayesinde       //
	        printf("Lutfen Once Kayit Ekleyiniz\n\n");                          //  Kayıt Yapılıp Yapılmadığı   //
	        break;                                                              //  anlaşılır                   //
	    }
		 
		 printf("Ad\tSoyad\tVize1\tVize2\tFinal\tNotu\tHarf\tDurumu\n");
		 
		 for(int i = 0 ; i<10 ; i++){
		     note[i]=round((vize1[i])*1/5 + (vize2[i])*3/10 + (final[i])*1/2);  //  Not hesaplanır //
		 }
		 
		 for(int i = 0; i < 9; i++) {                                           //  Bu Kısımda  //
        index = i;                                                              //  Notlar      //
        for(int j = i + 1; j < 10; j++) {                                       //  Büyükten    //
            if(note[index] < note[j]) {                                         //  Küçüğe      //
                index = j;                                                      //  Sıralanır   //
            }
        }
        if(index != i)
        {
            int temp = note[i];                                                 //  Notlar Büyükten Küçüğe  //
            note[i] = note[index];                                              //  Sıralanır               //
            note[index] = temp;
            
            int temp1 = vize1[i];                                               //  Not Sıralamasına göre   //
            vize1[i] = vize1[index];                                            //  Vize1 Yer Değiştirir    //
            vize1[index] = temp1;
            
            int temp2 = vize2[i];                                               //  Not Sıralamasına göre   //
            vize2[i] = vize2[index];                                            //  Vize2 Yer Değiştirir    //
            vize2[index] = temp2;
            
            int temp3 = final[i];                                               //  Not Sıralamasına Göre   //
            final[i] = final[index];                                            //  Final Yer Değiştirir    //
            final[index] = temp3;
            
            char *char1 = name[i];                                              //  Not Sıralamasına Göre   //
            name[i] = name[index];                                              //  Ad Yer Değiştirir       //
            name[index] = char1;
            
            char *char2 = lname[i];                                             //  Not Sıralamasına Göre   //
            lname[i] = lname[index];                                            //  Soyad Yer Değiştirir    //
            lname[index] = char2;
        }
    }
            for(int i=0 ; i<10 ; i++){                                          //  Bu Kısımda  //
                printf("%s\t",name[i]);                                         //  Veriler     //
		        printf("%c.\t",lname[i][0]);                                    //  Ekrana      //
		        printf("%d\t",(int)vize1[i]);                                   //  Yazdırılır  //
		        printf("%d\t",(int)vize2[i]);
		        printf("%d\t",(int)final[i]);
		        printf("%d\t",note[i]);
		        
		        if(note[i]>89){                                                 //  Bu Kısımda  //
		            printf("AA\tGecti");                                        //  Notlara Göre//
		        }                                                               //  Harf Notu   //
		        else if((note[i]<90)&&(note[i]>84)){                            //  Kaldı-Geçti //
		            printf("BA\tGecti");                                        //  Durumu      //
		        }                                                               //  Ekrana      //
		        else if((note[i]<85)&&(note[i]>79)){                            //  Yazdırılır  //
		            printf("BB\tGecti");
		        }
		        else if((note[i]<80)&&(note[i]>74)){
		            printf("CB\tGecti");
		        }
		        else if((note[i]<75)&&(note[i]>69)){
		            printf("CC\tGecti");
		        }
		        else if((note[i]<70)&&(note[i]>64)){
		            printf("DC\tGecti");
		        }
		        else if((note[i]<65)&&(note[i]>59)){
		            printf("DD\tGecti");
		        }
		        else if((note[i]<60)&&(note[i]>49)){
		            printf("FD\tSartli Gecti");
		        }
		        else {
		            printf("FF\tKaldi");
		        }
		        printf("\n");
		    }
		    printf("\n");
		    break;
		    
		    case 5:
		    if(o==0){                                                           //  "o" Değişkeni Sayesinde      //
	        printf("Lutfen Once Kayit Ekleyiniz\n\n");                          //  Kayıt Yapılıp Yapılmadığı    //
	        break;                                                              //  Anlaşılır                    //
	    }
		    for(int i = 0 ; i<10 ; i++){
		     note[i]=round((vize1[i])*1/5 + (vize2[i])*3/10 + (final[i])*1/2);
		 }
		    for(int i = 0; i < 9; i++) {                                        //  Bu Kısımda  //
                index = i;                                                      //  Notlar      //
                for(int j = i + 1; j < 10; j++) {                               //  Büyükten    //
                  if(note[index] < note[j]) {                                   //  Küçüğe      //
                        index = j;                                              //  Sıralanır   //
                  }
                }
                if(index != i)
                {
                    int temp = note[i];
                    note[i] = note[index];
                    note[index] = temp;
                 }
		    }
		    for(int i = 0 ; i<10 ; i++){                                        //  Bu Kısımda  //
		        ort = ort + note[i];                                            //  Ortalama    //
		    }                                                                   //  Hesaplanır  //
		    ort = ort/10; 
		    
		    for(int j = 0 ; j < 10 ; j++){                                      //  Bu Kısımda  //
		        if(ort > note[j]){                                              //  Standart    //
		            std = std + ((ort - note[j])*(ort - note[j]));              //  Sapma       //
		        }                                                               //  Hesaplanır  //
		        else{                                                           
		            std = std + ((note[j] - ort)*(note[j] - ort));              
		        }                                                               
		        std = sqrt(std/9);                                              
		        
		    }
		    for(int i = 0 ; i < 10 ; i++){                                      //  Bu Kısımda      //
		        if(note[i] > ort){                                              //  Ortalama Üstü   //
		            sayac = sayac + 1;                                          //  Kişi Sayısı     //
		        }                                                               //  Heasplanır      //
		    }
		    printf("\n---Istatistiki bilgiler---\n");                           //  Bu Kısımda      //
		    printf("En Yuksek Not : %d\n",note[0]);                             //  Bulunan Veriler //
		    printf("En Dusuk Not : %d\n",note[9]);                              //  Sırasıyla       //
		    printf("Sinif Ortalaması : %d\n",ort);                              //  Ekrana          //
		    printf("Ortalama Ustu Kisi Sayisi : %d",sayac);                     //  Yazdırılır      //
		    printf(" - Basari Orani : %d",sayac*10);
		    printf("\nStandart Sapma : %.2f\n\n",std);
		    break;
		    
		    case 6:
		    bilgi();
		    break;
		    default:
		    printf("Hatali Tuslama Yaptiniz\n\n");                              
		    
	}
	}
    
	return 0;
}

void menu(){
    	printf("Menu\n1-Kayit Ekle\n2-Kayitları Listele\n3-Sinif Basari Notlarini Hesapla\n4-Kaytlari Basari Notuna Gore Sirala\n5-Isiatistiki Bilgiler\n6-Cikis\n\nBir Islem Seciniz :");
}

void kayit(char ad[10][20],char soyad[10][20],float vize1[10],float vize2[10],float final[10]){     //  Bu Kısımda      //
                                                                                                    //  Kullanıcıdan    //
    printf("\n\n---Kayit Ekle---\n");                                                               //  Ad, Soyad       //
			for(int i=0; i < 10; i++){                                                              //  Vize1, Vize2    //
				printf("%d. Adi : ", i + 1);                                                        //  Final Değerleri Alınır  //
				scanf("%s" , ad[i]);
				printf("%d. Soyadı : ", i + 1);
				scanf("%s" , soyad[i]);
				printf("%d. 1. Ara Sinav , 2. Ara Sinav , Final : ", i + 1);
				scanf("%f" , &vize1[i]);
				scanf("%f" , &vize2[i]);
				scanf("%f" , &final[i]);
			}
			
	printf("Ad\tSoyad\tVize1\tVize2\tFinal\n");
		
		    for(int k=0; k<10; k++){                                            //  Bu Kısımda Alınan Veriler   //
		        printf("%s\t",ad[k]);                                           //  Sırasıyla Ekrana Yazdırılır //
		        printf("%c.\t",soyad[k][0]);
		        printf("%d\t",(int)vize1[k]);
		        printf("%d\t",(int)vize2[k]);
		        printf("%d\t",(int)final[k]);
		        printf("\n");
			}
		     	printf("\n");
    
    
}
void bilgi(){
	printf("Cikis Yaptiniz!\n\nProgram Sahibi Hakkinda Bilgi \n");              //  Kullanıcı Hakkında Bilgiler //       
	
    printf("Ad Soyad :Berk Karaman\nNumara : \nBölüm : Bilgisayar Muhendisliği 2. Sinif Orgün Ogretim");
}