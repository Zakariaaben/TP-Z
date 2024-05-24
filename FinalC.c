  /**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             Réalisée par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/

  #include <stdio.h>
  #include <stdlib.h>
  #include <Time.h>
  #include <windows.h>
  #include <conio.h>

  typedef int bool ;

  #define True 1
  #define False 0

  /** Implémentation **\: ARBRE BINAIRE DE STRUCTURES**/

  /** Structures statiques **/

  typedef struct Tib Type_Tib  ;
  typedef Type_Tib * Typestr_Tib ;
  typedef int Type1_Tib  ;
  typedef bool Type2_Tib  ;
  struct Tib
    {
      Type1_Tib Champ1 ;
      Type2_Tib Champ2 ;
    };

  Type1_Tib Struct1_Tib ( Typestr_Tib S)
    {
      return  S->Champ1 ;
    }

  Type2_Tib Struct2_Tib ( Typestr_Tib S)
    {
      return  S->Champ2 ;
    }

  void Aff_struct1_Tib ( Typestr_Tib S, Type1_Tib Val )
    {
       S->Champ1 = Val ;
    }

  void Aff_struct2_Tib ( Typestr_Tib S, Type2_Tib Val )
    {
       S->Champ2 = Val ;
    }


  /** Arbres de recherche binaire **/

  typedef Typestr_Tib Typeelem_ATib   ;
  typedef struct Noeud_ATib * Pointeur_ATib ;

  struct Noeud_ATib
    {
      Typeelem_ATib  Val ;
      Pointeur_ATib Fg ;
      Pointeur_ATib Fd ;
      Pointeur_ATib Pere ;
     } ;

  Typeelem_ATib Info_ATib( Pointeur_ATib P )
    { return P->Val;   }

  Pointeur_ATib Fg_ATib( Pointeur_ATib P)
    { return P->Fg ; }

  Pointeur_ATib Fd_ATib( Pointeur_ATib P)
    { return P->Fd ; }

  Pointeur_ATib Pere_ATib( Pointeur_ATib P)
    { return P->Pere ; }

  void Aff_info_ATib ( Pointeur_ATib P, Typeelem_ATib Val)
    {
      Typeelem_ATib _Temp ;
      _Temp = malloc(sizeof(Type_Tib));
      /* Affectation globale de structure */
      _Temp->Champ1 = Val->Champ1;
      _Temp->Champ2 = Val->Champ2;
      Val = _Temp ;
       P->Val = Val ;
    }

  void Aff_fg_ATib( Pointeur_ATib P, Pointeur_ATib Q)
    { P->Fg =  Q;  }

  void Aff_fd_ATib( Pointeur_ATib P, Pointeur_ATib Q)
    { P->Fd =  Q ; }

  void Aff_pere_ATib( Pointeur_ATib P, Pointeur_ATib Q)
    { P->Pere =  Q ; }

  void Creernoeud_ATib( Pointeur_ATib *P)
    {
      *P = (struct Noeud_ATib *) malloc( sizeof( struct Noeud_ATib))   ;
      (*P)->Val = malloc(sizeof(Type_Tib));
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_ATib( Pointeur_ATib P)
    { free( P ) ; }


  /** Implémentation **\: FILE DE ENTIERS**/
  /** Files d'attente **/

  typedef int Typeelem_Fi ;
  typedef  struct Filedattente_Fi * Pointeur_Fi ;
  typedef  struct Maillon_Fi * Ptliste_Fi ;

  struct Maillon_Fi
    {
      Typeelem_Fi Val ;
      Ptliste_Fi Suiv  ;
    };

  struct Filedattente_Fi
    {
      Ptliste_Fi Tete, Queue ;
    };

  void Creerfile_Fi ( Pointeur_Fi *Fil   )
    {
      *Fil = (struct Filedattente_Fi *) malloc( sizeof( struct Filedattente_Fi)) ;
      (*Fil)->Tete = NULL ;
      (*Fil)->Queue = NULL ;
    }

  bool Filevide_Fi (Pointeur_Fi Fil  )
    { return  Fil->Tete == NULL ;}

  void Enfiler_Fi ( Pointeur_Fi Fil , Typeelem_Fi Val   )
    {
      Ptliste_Fi Q;

      Q = (struct Maillon_Fi *) malloc( sizeof( struct Maillon_Fi))   ;
      Q->Val = Val ;
      Q->Suiv = NULL;
      if ( ! Filevide_Fi(Fil) )
        Fil->Queue->Suiv = Q ;
      else Fil->Tete = Q;
        Fil->Queue = Q;
    }

  void Defiler_Fi (Pointeur_Fi Fil, Typeelem_Fi *Val )
    {
      if (! Filevide_Fi(Fil) )
        {
          *Val = Fil->Tete->Val ;
          Fil->Tete =  Fil->Tete->Suiv;
        }
      else printf ("%s \n", "File d'attente vide");
    }


  /** Implémentation **\: TABLEAU DE ARBRES BINAIRES DE STRUCTURES**/

  /** Tableaux **/

  typedef Pointeur_ATib Typeelem_V10ATib ;
  typedef Typeelem_V10ATib * Typevect_V10ATib ;

  Typeelem_V10ATib Element_V10ATib ( Typevect_V10ATib V , int I1  )
    {
      return  *(V +  (I1-1)  ) ;
    }

  void Aff_element_V10ATib ( Typevect_V10ATib V  , int I1 ,  Typeelem_V10ATib Val )
    {
      *(V +  (I1-1)  ) = Val ;
    }


  /** Implémentation **\: LISTE DE ENTIERS**/

  /** Listes lin?aires cha?n?es **/

  typedef int Typeelem_Li   ;
  typedef struct Maillon_Li * Pointeur_Li ;

  struct Maillon_Li
    {
      Typeelem_Li  Val ;
      Pointeur_Li Suiv ;
    } ;

  Pointeur_Li Allouer_Li (Pointeur_Li *P)
    {
      *P = (struct Maillon_Li *) malloc( sizeof( struct Maillon_Li)) ;
      (*P)->Suiv = NULL;
    }

  void Aff_val_Li(Pointeur_Li P, Typeelem_Li Val)
    {
      P->Val = Val ;
    }

  void Aff_adr_Li( Pointeur_Li P,  Pointeur_Li Q)
    {
      P->Suiv = Q ;
    }

  Pointeur_Li Suivant_Li(  Pointeur_Li P)
    { return( P->Suiv ) ;  }

  Typeelem_Li Valeur_Li( Pointeur_Li P)
    { return( P->Val) ; }

  void Liberer_Li ( Pointeur_Li P)
    { free (P);}


  /** Implémentation **\: PILE DE STRUCTURES**/
  /** Piles **/

  typedef Typestr_Tib Typeelem_PTib ;
  typedef struct Maillon_PTib * Pointeur_PTib ;
  typedef   Pointeur_PTib  Typepile_PTib  ;

  struct Maillon_PTib
    {
      Typeelem_PTib  Val ;
      Pointeur_PTib Suiv ;
    } ;

  void Creerpile_PTib( Pointeur_PTib *P )
    { *P = NULL ; }

  bool Pilevide_PTib ( Pointeur_PTib P )
    { return  (P == NULL ); }

  void Empiler_PTib ( Pointeur_PTib *P,  Typeelem_PTib Val )
    {
      Pointeur_PTib Q;

      Q = (struct Maillon_PTib *) malloc( sizeof( struct Maillon_PTib))   ;
      Q->Val = malloc(sizeof(Type_Tib));
      Typeelem_PTib _Temp ;
      _Temp = malloc(sizeof(Type_Tib));
      /* Affectation globale de structure */
      _Temp->Champ1 = Val->Champ1;
      _Temp->Champ2 = Val->Champ2;
      Val = _Temp ;
      Q->Val = Val ;
      Q->Suiv = *P;
      *P = Q;
    }

  void Depiler_PTib ( Pointeur_PTib *P,  Typeelem_PTib *Val )
    {
      Pointeur_PTib Sauv;

      if (! Pilevide_PTib (*P) )
        {
          *Val = (*P)->Val ;
          Sauv = *P;
          *P = (*P)->Suiv;
          free(Sauv);
        }
      else printf ("%s \n", "Pile vide");
    }


  /** Implémentation **\: PILE DE ARBRES BINAIRES DE STRUCTURES**/
  /** Piles **/

  typedef Pointeur_ATib Typeelem_PATib ;
  typedef struct Maillon_PATib * Pointeur_PATib ;
  typedef   Pointeur_PATib  Typepile_PATib  ;

  struct Maillon_PATib
    {
      Typeelem_PATib  Val ;
      Pointeur_PATib Suiv ;
    } ;

  void Creerpile_PATib( Pointeur_PATib *P )
    { *P = NULL ; }

  bool Pilevide_PATib ( Pointeur_PATib P )
    { return  (P == NULL ); }

  void Empiler_PATib ( Pointeur_PATib *P,  Typeelem_PATib Val )
    {
      Pointeur_PATib Q;

      Q = (struct Maillon_PATib *) malloc( sizeof( struct Maillon_PATib))   ;
      Q->Val = Val ;
      Q->Suiv = *P;
      *P = Q;
    }

  void Depiler_PATib ( Pointeur_PATib *P,  Typeelem_PATib *Val )
    {
      Pointeur_PATib Sauv;

      if (! Pilevide_PATib (*P) )
        {
          *Val = (*P)->Val ;
          Sauv = *P;
          *P = (*P)->Suiv;
          free(Sauv);
        }
      else printf ("%s \n", "Pile vide");
    }


  /** Implémentation **\: FILE DE ARBRES BINAIRES DE STRUCTURES**/
  /** Files d'attente **/

  typedef Pointeur_ATib Typeelem_FATib ;
  typedef  struct Filedattente_FATib * Pointeur_FATib ;
  typedef  struct Maillon_FATib * Ptliste_FATib ;

  struct Maillon_FATib
    {
      Typeelem_FATib Val ;
      Ptliste_FATib Suiv  ;
    };

  struct Filedattente_FATib
    {
      Ptliste_FATib Tete, Queue ;
    };

  void Creerfile_FATib ( Pointeur_FATib *Fil   )
    {
      *Fil = (struct Filedattente_FATib *) malloc( sizeof( struct Filedattente_FATib)) ;
      (*Fil)->Tete = NULL ;
      (*Fil)->Queue = NULL ;
    }

  bool Filevide_FATib (Pointeur_FATib Fil  )
    { return  Fil->Tete == NULL ;}

  void Enfiler_FATib ( Pointeur_FATib Fil , Typeelem_FATib Val   )
    {
      Ptliste_FATib Q;

      Q = (struct Maillon_FATib *) malloc( sizeof( struct Maillon_FATib))   ;
      Q->Val = Val ;
      Q->Suiv = NULL;
      if ( ! Filevide_FATib(Fil) )
        Fil->Queue->Suiv = Q ;
      else Fil->Tete = Q;
        Fil->Queue = Q;
    }

  void Defiler_FATib (Pointeur_FATib Fil, Typeelem_FATib *Val )
    {
      if (! Filevide_FATib(Fil) )
        {
          *Val = Fil->Tete->Val ;
          Fil->Tete =  Fil->Tete->Suiv;
        }
      else printf ("%s \n", "File d'attente vide");
    }

   
  /** Variables du programme principal **/
  Pointeur_ATib Monarbre=NULL;
  Pointeur_Fi L=NULL;
  bool B;
  int Choix;
  bool Generes;
  Typevect_V10ATib Tableaudebst;
  int Choixarbre;
  int Jetable;
  Pointeur_Li Listofelements=NULL;
  int _Px1;
  Pointeur_ATib _Px2=NULL;
  Pointeur_ATib _Px3=NULL;
  Pointeur_ATib _Px4=NULL;
  Pointeur_ATib _Px5=NULL;
  Pointeur_ATib _Px6=NULL;
  Pointeur_ATib _Px7=NULL;
  Pointeur_ATib _Px8=NULL;
  Pointeur_ATib _Px9=NULL;
  Pointeur_ATib _Px10=NULL;

  /** Fonctions standards **/

  int Aleanombre( int N )
    { return ( rand() % N ); }


  /** Initialisation d'une structure **/
  void Init_struct_Tib ( Typestr_Tib S, Type_Tib S_ )
    {
      S->Champ1 = S_.Champ1 ;
      S->Champ2 = S_.Champ2 ;
    }


  /** Prototypes des fonctions **/

  void Menu();
  void Etiquette();
  void Afficherarbre (Pointeur_ATib *R);
  bool  Verifytreeinorder (Pointeur_ATib *Root) ;
  void Inordrepush (Pointeur_ATib *Root , Pointeur_PTib *P);
  void Resettree (Pointeur_ATib *R);
  bool  Search (Pointeur_ATib *Root , int *Value) ;
  void Inserer (Pointeur_ATib *Root , int *Value);
  void Generatetree (Pointeur_ATib *Root , int *N);
  void Traversal1 (Pointeur_ATib *Root , Pointeur_Li *L);
  bool  Verifytraversal1 (Pointeur_ATib *Root , Pointeur_Li *L1) ;
  void Enfilerinordre (Pointeur_ATib *Root , Pointeur_Fi *Q);
  void Traversal2 (Pointeur_ATib *Root , Pointeur_Li *L);
  void Enqueueleaves (Pointeur_ATib *Root , Pointeur_FATib *Q);
  bool  Verifytraversal2 (Pointeur_ATib *Root , Pointeur_Li *List) ;
  void Enfilerverify2 (Pointeur_ATib *Root , Pointeur_FATib *L);
  void Ajouteralafin (Pointeur_Li *Head , int *Val);
  void Traversal3 (Pointeur_ATib *Root , Pointeur_Li *L);
  bool  Verifytraversal3 (Pointeur_ATib *Root , Pointeur_Li *L1) ;
  void Enfilerinordre3 (Pointeur_ATib *Root , Pointeur_Fi *Q);
  void Traversal4 (Pointeur_ATib *Root , Pointeur_Li *L);
  void Enqueueleavesrev (Pointeur_ATib *Root , Pointeur_FATib *Q);
  bool  Verifytraversal4 (Pointeur_ATib *Root , Pointeur_Li *List) ;
  void Enfilerverify4 (Pointeur_ATib *Root , Pointeur_FATib *L);

  /* 
   */
  /* 
   */
  /*************    Menu *************/
  void Menu()
    {

      /** Corps du module **/
     printf ( " %s", "" ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "Veuillez entrer un choix (1-3)" ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "      1 - Génerer Arbres Binaires " ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "      2 - Appliquer Traversals" ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "      3 - Exit" ) ;
     printf ( " %s", "" ) ;
    
    }
  /*************************************/
  void Etiquette()
    {

      /** Corps du module **/
    printf ( " %s", "                    |**********************************************************************************|\n" ) ;
     printf ( " %s", "                    |***********************   TP Z  BST Traversals 2023/2034   ***********************|\n" ) ;
     printf ( " %s", "                    |******************      By Benyahia Alia & Benhamiche Zakaria       **************|\n" ) ;
     printf ( " %s", "                    |__________________________________________________________________________________|\n\n" ) ;
    
    }
  /****************************                    Fonction affichage *************************/
  void Afficherarbre (Pointeur_ATib *R)
    {
      /** Variables locales **/
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     if( *R != NULL) {
       _Px1 =  Fg_ATib ( *R ) ;
       Afficherarbre ( &_Px1) ;
       printf ( " %d", Struct1_Tib(Info_ATib(*R)) ) ;
       _Px2 =  Fd_ATib ( *R ) ;
       Afficherarbre ( &_Px2) ;
      
     }
    }
  /* 
   */
  /*************************       Verification Creation BST *************************/
  bool  Verifytreeinorder (Pointeur_ATib *Root) 
    {
      /** Variables locales **/
      bool  Verifytreeinorder2 ;
      Pointeur_PTib P=NULL;
      Typestr_Tib A;
      Typestr_Tib B;

      /** Corps du module **/
     A = malloc(sizeof(Type_Tib));
     B = malloc(sizeof(Type_Tib));
     Inordrepush ( & *Root , & P ) ;
     Verifytreeinorder2  =  True ;
     if( ! Pilevide_PTib ( P )) {
       Depiler_PTib (& P , &A ) ;
      
     } ;
     while( ( ! ( Pilevide_PTib ( P ) ) )) {
       Depiler_PTib (& P , &B ) ;
       if( Struct1_Tib ( A  ) < Struct1_Tib ( B  ))   {
         Verifytreeinorder2  =  False ;
        
       } ;
      /* Affectation globale de structure */
       A->Champ1 =   B->Champ1;
       A->Champ2 =   B->Champ2;
 ;
      
     }
     return Verifytreeinorder2 ;
    }
  /* 
   */
  /****************************        Push noeuds Inordre ****************************/
  void Inordrepush (Pointeur_ATib *Root , Pointeur_PTib *P)
    {
      /** Variables locales **/
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     if( *Root != NULL) {
       _Px1 =  Fg_ATib ( *Root ) ;
       Inordrepush ( &_Px1, & *P ) ;
       Empiler_PTib (& *P , Info_ATib ( *Root ) ) ;
       _Px2 =  Fd_ATib ( *Root ) ;
       Inordrepush ( &_Px2, & *P ) ;
      
     }
    }
  /* 
   */
  /*************************       Renitialiser Noeuds visités ************************/
  void Resettree (Pointeur_ATib *R)
    {
      /** Variables locales **/
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     if( *R != NULL)   {
       _Px1 =  Fg_ATib ( *R ) ;
       Resettree ( &_Px1) ;
       Aff_struct2_Tib ( Info_ATib ( *R )  , False ) ;
       _Px2 =  Fd_ATib ( *R ) ;
       Resettree ( &_Px2) ;
      
     } ;
    
    }
  /* 
   */
  /*************************       Rechercher noeud dans BST ************************/
  bool  Search (Pointeur_ATib *Root , int *Value) 
    {
      /** Variables locales **/
      bool  Search2 ;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     if( *Root != NULL) {
       if( *Value == Struct1_Tib ( Info_ATib ( *Root )  )) {
         Search2  =  True ;
         }
       else
         {
         if( *Value > Struct1_Tib ( Info_ATib ( *Root )  )) {
           _Px1 =  Fd_ATib ( *Root ) ;
           Search2  =  Search ( &_Px1, & *Value ) ;
           }
         else
           {
           _Px2 =  Fg_ATib ( *Root ) ;
           Search2  =  Search ( &_Px2, & *Value ) ;
          
         } ;
        
       } ;
       }
     else
       {
       Search2  =  False ;
      
     } ;
    
     return Search2 ;
    }
  /* 
   */
  /*************************        Inserer Noeud dans BST *************************/
  void Inserer (Pointeur_ATib *Root , int *Value)
    {
      /** Variables locales **/
      Pointeur_ATib P=NULL;
      Typestr_Tib New;
      Type_Tib S_New;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     New = malloc(sizeof(Type_Tib));
     if( *Root == NULL)   {
       Creernoeud_ATib (& *Root ) ;
       S_New.Champ1 = *Value ;
       S_New.Champ2 = False ;
       Init_struct_Tib ( New , S_New )  ;
       Aff_info_ATib ( *Root , New ) ;
       }
     else
       {
       if( ( ( *Value < Struct1_Tib ( Info_ATib ( *Root )  ) ) && ( Fg_ATib ( *Root ) == NULL ) ))   {
         Creernoeud_ATib (& P ) ;
         S_New.Champ1 = *Value ;
         S_New.Champ2 = False ;
         Init_struct_Tib ( New , S_New )  ;
         Aff_info_ATib ( P , New ) ;
         Aff_pere_ATib ( P , *Root ) ;
         Aff_fg_ATib ( *Root , P ) ;
         }
       else
         {
         if( ( ( *Value >= Struct1_Tib ( Info_ATib ( *Root )  ) ) && ( Fd_ATib ( *Root ) == NULL ) ))   {
           Creernoeud_ATib (& P ) ;
           S_New.Champ1 = *Value ;
           S_New.Champ2 = False ;
           Init_struct_Tib ( New , S_New )  ;
           Aff_info_ATib ( P , New ) ;
           Aff_pere_ATib ( P , *Root ) ;
           Aff_fd_ATib ( *Root , P ) ;
           }
         else
           {
           if( ( ( *Value < Struct1_Tib ( Info_ATib ( *Root )  ) ) && ( Fg_ATib ( *Root ) != NULL ) )) {
             _Px1 =  Fg_ATib ( *Root ) ;
             Inserer ( &_Px1, & *Value ) ;
             }
           else
             {
             _Px2 =  Fd_ATib ( *Root ) ;
             Inserer ( &_Px2, & *Value ) ;
            
           }
         }
       }
     }
    }
  /* 
   */
  /***************************GGGGenerer ARBRE BST ***************************/
  void Generatetree (Pointeur_ATib *Root , int *N)
    {
      /** Variables locales **/
      int I;
      int A;

      /** Corps du module **/
     for( I  =  1 ;I <=  *N   ; ++I){
       A  =  Aleanombre(300 ) ;
       while( Search ( & *Root , & A ))  {
         A  =  Aleanombre(300 ) ;
        
       } ;
       Inserer ( & *Root , & A ) ;
      
     } ;
    
    }
  /* 
   */
  /***********************TTTTTTraversal 1 BB-LR-Bottom To Top ***********************/
  void Traversal1 (Pointeur_ATib *Root , Pointeur_Li *L)
    {
      /** Variables locales **/
      Pointeur_PATib Stack=NULL;
      Pointeur_ATib Q=NULL;
      int A;
      int _Px1;

      /** Corps du module **/
     Q  =  *Root ;
      int anumber=0;
    
    if( Q == NULL)   {

       printf ( " %s", "L arbre est vide" ) ;
       }
     else
       {
       while( ( Q != NULL )) {
         if( ( ( Fg_ATib ( Q ) != NULL ) && ( Fd_ATib ( Q ) != NULL ) ))   {
           Empiler_PATib (& Stack , Fd_ATib ( Q ) );
         } ;
         if( ( Fg_ATib ( Q ) != NULL )) {
           Q  =  Fg_ATib ( Q ) ;
           }
         else
           {
           if( ( Fd_ATib ( Q ) != NULL )) {
             Q  =  Fd_ATib ( Q ) ;
            
           } ;
          
         } ;
         if( ( ( Fg_ATib ( Q ) == NULL ) && ( Fd_ATib ( Q ) == NULL ) )) {
           while( ( Q != NULL )) {
             if( ( Struct2_Tib ( Info_ATib ( Q )  ) == False )) {
                anumber++;
               printf ( "  | %d | -> ", Struct1_Tib(Info_ATib(Q)) ) ;
               if (anumber % 8 == 0) printf("\n\n");

               _Px1 =  Struct1_Tib ( Info_ATib ( Q )  ) ;
               Ajouteralafin ( & *L , &_Px1) ;
               Aff_struct2_Tib ( Info_ATib ( Q )  , True ) ;
               Q  =  Pere_ATib ( Q ) ;
               }
             else
               {
               Q  =  NULL ;
              
             }
           } ;
           if( ( ! Pilevide_PATib ( Stack ) )) {
             Depiler_PATib (& Stack , &Q ) ;
            
           } ;
          
         } ;
        
       }
       printf(" END");
     } ;
    
   
     Resettree ( & *Root ) ;
    
    }
  /* 
   */
  /*********************      Verify Traversal 1 ******************************/
  bool  Verifytraversal1 (Pointeur_ATib *Root , Pointeur_Li *L1) 
    {
      /** Variables locales **/
      bool  Verifytraversal12 ;
      Pointeur_Li L2=NULL;
      Pointeur_Fi Q=NULL;
      int P;
      bool Egaux;

      /** Corps du module **/
     Creerfile_Fi (& Q ) ;
     Egaux  =  True ;
     L2  =  NULL ;
     Enfilerinordre ( & *Root , & Q ) ;
     while( ( ! Filevide_Fi ( Q ) )) {
       Defiler_Fi ( Q , &P ) ;
       Ajouteralafin ( & L2 , & P ) ;
      
     } ;
     while( ( ( L2 != NULL ) && Egaux )) {
       if( ( Valeur_Li ( *L1 ) != Valeur_Li ( L2 ) )) {
         Egaux  =  False ;
        
       } ;
       L2  =  Suivant_Li ( L2 ) ;
       *L1  =  Suivant_Li ( *L1 ) ;
      
     } ;
     Verifytraversal12  =  Egaux ;
    
     return Verifytraversal12 ;
    }
  /**************************************************************/
  void Enfilerinordre (Pointeur_ATib *Root , Pointeur_Fi *Q)
    {
      /** Variables locales **/
      Pointeur_ATib P=NULL;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     if( ( *Root != NULL )) {
       _Px1 =  Fg_ATib ( *Root ) ;
       Enfilerinordre ( &_Px1, & *Q ) ;
       if( ( ( Fg_ATib ( *Root ) == NULL ) && ( Fd_ATib ( *Root ) == NULL ) )) {
         P  =  *Root ;
         while( P != NULL) {
           Enfiler_Fi ( *Q , Struct1_Tib ( Info_ATib ( P )  ) ) ;
           P  =  Pere_ATib ( P ) ;
          
         } ;
        
       } ;
       _Px2 =  Fd_ATib ( *Root ) ;
       Enfilerinordre ( &_Px2, & *Q ) ;
      
     } ;
    
    }
  /***********************        Traversal 2  ***********************/
  void Traversal2 (Pointeur_ATib *Root , Pointeur_Li *L)
    {
      /** Variables locales **/
      Pointeur_FATib Q=NULL;
      Pointeur_ATib P=NULL;
      int _Px1;
      int anumber = 0;

      /** Corps du module **/
     Creerfile_FATib (& Q ) ;
     Enqueueleaves ( & *Root , & Q ) ;
     while( ! Filevide_FATib ( Q )) {
       ;
       Defiler_FATib ( Q , &P ) ;
       Aff_struct2_Tib ( Info_ATib ( P )  , True ) ;
       
       anumber++;
         printf ( "  | %d | -> ", Struct1_Tib(Info_ATib(P)) ) ;
        if (anumber % 8 == 0) printf("\n\n");
       _Px1 =  Struct1_Tib ( Info_ATib ( P )  ) ;
       Ajouteralafin ( & *L , &_Px1) ;
       if( Pere_ATib ( P ) != NULL) {
         if( ( Fg_ATib ( Pere_ATib ( P ) ) == NULL )) {
           if( Fd_ATib ( Pere_ATib ( P ) ) == NULL) {
             Enfiler_FATib ( Q , Pere_ATib ( P ) ) ;
             }
           else
             {
             if( ( Struct2_Tib ( Info_ATib ( Fd_ATib ( Pere_ATib ( P ) ) )  ) == True )) {
               Enfiler_FATib ( Q , Pere_ATib ( P ) ) ;
              
             } ;
            
           } ;
           }
         else
           {
           if( Struct2_Tib ( Info_ATib ( Fg_ATib ( Pere_ATib ( P ) ) )  ) == True) {
             if( Fd_ATib ( Pere_ATib ( P ) ) == NULL) {
               Enfiler_FATib ( Q , Pere_ATib ( P ) ) ;
               }
             else
               {
               if( Struct2_Tib ( Info_ATib ( Fd_ATib ( Pere_ATib ( P ) ) )  ) == True) {
                 Enfiler_FATib ( Q , Pere_ATib ( P ) ) ;
                
               } ;
              
             } ;
            
           } ;
          
         } ;
        
       } ;
      
     } ;
     printf(" END " );
     Resettree ( & *Root ) ;
    
    }
  /********************       Enqueue leaves **********************/
  void Enqueueleaves (Pointeur_ATib *Root , Pointeur_FATib *Q)
    {
      /** Variables locales **/
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     if( *Root != NULL) {
       _Px1 =  Fg_ATib ( *Root ) ;
       Enqueueleaves ( &_Px1, & *Q ) ;
       if( ( Fd_ATib ( *Root ) == NULL ) && ( Fg_ATib ( *Root ) == NULL )) {
         Enfiler_FATib ( *Q , *Root ) ;
        
       } ;
       _Px2 =  Fd_ATib ( *Root ) ;
       Enqueueleaves ( &_Px2, & *Q ) ;
      
     } ;
    
    }
  /******************        Verify Traversal 2    ****************************/
  bool  Verifytraversal2 (Pointeur_ATib *Root , Pointeur_Li *List) 
    {
      /** Variables locales **/
      bool  Verifytraversal22 ;
      Pointeur_FATib Temp=NULL;
      Pointeur_Fi L=NULL;
      bool Egaux;
      int A;
      Pointeur_ATib P=NULL;

      /** Corps du module **/
     Creerfile_Fi (& L ) ;
     Creerfile_FATib (& Temp ) ;
     Egaux  =  True ;
     while( ( Struct2_Tib ( Info_ATib ( *Root )  ) ) == False) {
       Enfilerverify2 ( & *Root , & Temp ) ;
      /* Enfile les noeuds consideres comme feuille */
       while( ! Filevide_FATib ( Temp )) {
         Defiler_FATib ( Temp , &P ) ;
         Aff_struct2_Tib ( Info_ATib ( P )  , True ) ;
        /* Les mets a visited*/
         Enfiler_Fi ( L , Struct1_Tib ( Info_ATib ( P )  ) ) ;
        
       } ;
      
     } ;
     Resettree ( & *Root ) ;
     while( ! Filevide_Fi ( L )) {
       Defiler_Fi ( L , &A ) ;
       if( Valeur_Li ( *List ) != A) {
         Egaux  =  False ;
        
       } ;
       *List  =  Suivant_Li ( *List ) ;
      
     } ;
     Verifytraversal22  =  Egaux ;
     Resettree ( & *Root ) ;
    
     return Verifytraversal22 ;
    }
  /*************************************/
  void Enfilerverify2 (Pointeur_ATib *Root , Pointeur_FATib *L)
    {
      /** Variables locales **/
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     if( *Root != NULL) {
       _Px1 =  Fg_ATib ( *Root ) ;
       Enfilerverify2 ( &_Px1, & *L ) ;
       if( ( Fg_ATib ( *Root ) == NULL )) {
         if( Fd_ATib ( *Root ) == NULL) {
           if( Struct2_Tib ( Info_ATib ( *Root )  ) == False) {
             Enfiler_FATib ( *L , *Root ) ;
            
           } ;
           }
         else
           {
           if( ( Struct2_Tib ( Info_ATib ( Fd_ATib ( *Root ) )  ) == True )) {
             if( Struct2_Tib ( Info_ATib ( *Root )  ) == False) {
               Enfiler_FATib ( *L , *Root ) ;
              
             } ;
            
           } ;
          
         } ;
         }
       else
         {
         if( Struct2_Tib ( Info_ATib ( Fg_ATib ( *Root ) )  ) == True) {
           if( Fd_ATib ( *Root ) == NULL) {
             if( Struct2_Tib ( Info_ATib ( *Root )  ) == False) {
               Enfiler_FATib ( *L , *Root ) ;
              
             } ;
             }
           else
             {
             if( Struct2_Tib ( Info_ATib ( Fd_ATib ( *Root ) )  ) == True) {
               if( Struct2_Tib ( Info_ATib ( *Root )  ) == False) {
                 Enfiler_FATib ( *L , *Root ) ;
                
               } ;
              
             } ;
            
           } ;
          
         } ;
        
       } ;
       _Px2 =  Fd_ATib ( *Root ) ;
       Enfilerverify2 ( &_Px2, & *L ) ;
      
     } ;
    
    }
  /**********************************************************************/
  void Ajouteralafin (Pointeur_Li *Head , int *Val)
    {
      /** Variables locales **/
      Pointeur_Li P=NULL;
      Pointeur_Li Q=NULL;
      bool Exist;

    /** Corps du module **/
     Exist  =  False ;
     if( *Head == NULL) {
       Allouer_Li (& *Head ) ;
       Aff_val_Li ( *Head , *Val ) ;
       }
     else
       {
       P  =  *Head ;
       while( ( ( Suivant_Li ( P ) != NULL ) && ( ! Exist ) )) {
         if( ( *Val == Valeur_Li ( P ) )) {
           Exist  =  True ;
          
         } ;
         P  =  Suivant_Li ( P ) ;
        
       } ;
       if( ( ! Exist )) {
         Allouer_Li (& Q ) ;
         Aff_val_Li ( Q , *Val ) ;
         Aff_adr_Li ( P , Q ) ;
        
       } ;
      
     } ;
    
    }
  /***********************************      Traversal 3       ******************************/
  void Traversal3 (Pointeur_ATib *Root , Pointeur_Li *L)
    {
      /** Variables locales **/
      Pointeur_PATib Stack=NULL;
      Pointeur_ATib Q=NULL;
      int A;
      int _Px1;
      int anumber=0;

      /** Corps du module **/
     Q  =  *Root ;
     if( Q == NULL)   {
       printf ( " %s", "L arbre est vide" ) ;
       }
     else
       {
       while( ( Q != NULL )) {
         if( ( ( Fd_ATib ( Q ) != NULL ) && ( Fg_ATib ( Q ) != NULL ) ))   {
           Empiler_PATib (& Stack , Fg_ATib ( Q ) );
         } ;
         if( ( Fd_ATib ( Q ) != NULL )) {
           Q  =  Fd_ATib ( Q ) ;
           }
         else
           {
           if( ( Fg_ATib ( Q ) != NULL )) {
             Q  =  Fg_ATib ( Q ) ;
            
           } ;
          
         } ;
         if( ( ( Fg_ATib ( Q ) == NULL ) && ( Fd_ATib ( Q ) == NULL ) )) {
           while( ( Q != NULL )) {
             if( ( Struct2_Tib ( Info_ATib ( Q )  ) == False )) {
               anumber++;
         printf ( "  | %d | -> ", Struct1_Tib(Info_ATib(Q)) ) ;
        if (anumber % 8 == 0) printf("\n\n");
               _Px1 =  Struct1_Tib ( Info_ATib ( Q )  ) ;
               Ajouteralafin ( & *L , &_Px1) ;
               Aff_struct2_Tib ( Info_ATib ( Q )  , True ) ;
               Q  =  Pere_ATib ( Q ) ;
               }
             else
               {
               Q  =  NULL ;
              
             }
           } ;
           if( ( ! Pilevide_PATib ( Stack ) )) {
             Depiler_PATib (& Stack , &Q ) ;
            
           } ;
          
         } ;
        
       }
     } ;
     printf(" END ");
     Resettree ( & *Root ) ;
    
    }
  /* 
   */
  /*********************      Verify Traversal 3 ******************************/
  bool  Verifytraversal3 (Pointeur_ATib *Root , Pointeur_Li *L1) 
    {
      /** Variables locales **/
      bool  Verifytraversal32 ;
      Pointeur_Li L2=NULL;
      Pointeur_Fi Q=NULL;
      int P;
      bool Egaux;

      /** Corps du module **/
     Creerfile_Fi (& Q ) ;
     Egaux  =  True ;
     L2  =  NULL ;
     Enfilerinordre3 ( & *Root , & Q ) ;
     while( ( ! Filevide_Fi ( Q ) )) {
       Defiler_Fi ( Q , &P ) ;
       Ajouteralafin ( & L2 , & P ) ;
      
     } ;
     while( ( ( L2 != NULL ) && Egaux )) {
       if( ( Valeur_Li ( *L1 ) != Valeur_Li ( L2 ) )) {
         Egaux  =  False ;
        
       } ;
       L2  =  Suivant_Li ( L2 ) ;
       *L1  =  Suivant_Li ( *L1 ) ;
      
     } ;
     Verifytraversal32  =  Egaux ;
    
     return Verifytraversal32 ;
    }
  /**************************************************************/
  void Enfilerinordre3 (Pointeur_ATib *Root , Pointeur_Fi *Q)
    {
      /** Variables locales **/
      Pointeur_ATib P=NULL;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     if( ( *Root != NULL )) {
       _Px1 =  Fd_ATib ( *Root ) ;
       Enfilerinordre3 ( &_Px1, & *Q ) ;
       if( ( ( Fg_ATib ( *Root ) == NULL ) && ( Fd_ATib ( *Root ) == NULL ) )) {
         P  =  *Root ;
         while( P != NULL) {
           Enfiler_Fi ( *Q , Struct1_Tib ( Info_ATib ( P )  ) ) ;
           P  =  Pere_ATib ( P ) ;
          
         } ;
        
       } ;
       _Px2 =  Fg_ATib ( *Root ) ;
       Enfilerinordre3 ( &_Px2, & *Q ) ;
      
     } ;
    
    }
  /***********************        Traversal 4  ***********************/
  void Traversal4 (Pointeur_ATib *Root , Pointeur_Li *L)
    {
      /** Variables locales **/
      Pointeur_FATib Q=NULL;
      Pointeur_ATib P=NULL;
      int _Px1;
      int anumber = 0;

      /** Corps du module **/
     Creerfile_FATib (& Q ) ;
     Enqueueleavesrev ( & *Root , & Q ) ;
     while( ! Filevide_FATib ( Q )) {
       Defiler_FATib ( Q , &P ) ;
       Aff_struct2_Tib ( Info_ATib ( P )  , True ) ;
       anumber++;
         printf ( "  | %d | -> ", Struct1_Tib(Info_ATib(P)) ) ;
        if (anumber % 8 == 0) printf("\n\n");
       _Px1 =  Struct1_Tib ( Info_ATib ( P )  ) ;
       Ajouteralafin ( & *L , &_Px1) ;
       if( Pere_ATib ( P ) != NULL) {
         if( ( Fg_ATib ( Pere_ATib ( P ) ) == NULL )) {
           if( Fd_ATib ( Pere_ATib ( P ) ) == NULL) {
             Enfiler_FATib ( Q , Pere_ATib ( P ) ) ;
             }
           else
             {
             if( ( Struct2_Tib ( Info_ATib ( Fd_ATib ( Pere_ATib ( P ) ) )  ) == True )) {
               Enfiler_FATib ( Q , Pere_ATib ( P ) ) ;
              
             } ;
            
           } ;
           }
         else
           {
           if( Struct2_Tib ( Info_ATib ( Fg_ATib ( Pere_ATib ( P ) ) )  ) == True) {
             if( Fd_ATib ( Pere_ATib ( P ) ) == NULL) {
               Enfiler_FATib ( Q , Pere_ATib ( P ) ) ;
               }
             else
               {
               if( Struct2_Tib ( Info_ATib ( Fd_ATib ( Pere_ATib ( P ) ) )  ) == True) {
                 Enfiler_FATib ( Q , Pere_ATib ( P ) ) ;
                
               } ;
              
             } ;
            
           } ;
          
         } ;
        
       } ;
      
     } ;
     printf(" END");
     Resettree ( & *Root ) ;
    
    }
  /********************       Enqueue leaves reverse **********************/
  void Enqueueleavesrev (Pointeur_ATib *Root , Pointeur_FATib *Q)
    {
      /** Variables locales **/
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     if( *Root != NULL) {
       _Px1 =  Fd_ATib ( *Root ) ;
       Enqueueleavesrev ( &_Px1, & *Q ) ;
       if( ( Fd_ATib ( *Root ) == NULL ) && ( Fg_ATib ( *Root ) == NULL )) {
         Enfiler_FATib ( *Q , *Root ) ;
        
       } ;
       _Px2 =  Fg_ATib ( *Root ) ;
       Enqueueleavesrev ( &_Px2, & *Q ) ;
      
     } ;
    
    }
  /******************        Verify Traversal 4    ****************************/
  bool  Verifytraversal4 (Pointeur_ATib *Root , Pointeur_Li *List) 
    {
      /** Variables locales **/
      bool  Verifytraversal42 ;
      Pointeur_FATib Temp=NULL;
      Pointeur_Fi L=NULL;
      bool Egaux;
      int A;
      Pointeur_ATib P=NULL;

      /** Corps du module **/
     Creerfile_Fi (& L ) ;
     Creerfile_FATib (& Temp ) ;
     Egaux  =  True ;
     while( ( Struct2_Tib ( Info_ATib ( *Root )  ) ) == False) {
       Enfilerverify4 ( & *Root , & Temp ) ;
      /* Enfile les noeuds consideres comme feuille */
       while( ! Filevide_FATib ( Temp )) {
         Defiler_FATib ( Temp , &P ) ;
         Aff_struct2_Tib ( Info_ATib ( P )  , True ) ;
        /* Les mets a visited*/
         Enfiler_Fi ( L , Struct1_Tib ( Info_ATib ( P )  ) ) ;
        
       } ;
      
     } ;
     Resettree ( & *Root ) ;
     while( ! Filevide_Fi ( L )) {
       Defiler_Fi ( L , &A ) ;
       if( Valeur_Li ( *List ) != A) {
         Egaux  =  False ;
        
       } ;
       *List  =  Suivant_Li ( *List ) ;
      
     } ;
     Verifytraversal42  =  Egaux ;
     Resettree ( & *Root ) ;
    
     return Verifytraversal42 ;
    }
  /*************************************/
  void Enfilerverify4 (Pointeur_ATib *Root , Pointeur_FATib *L)
    {
      /** Variables locales **/
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     if( *Root != NULL) {
       _Px1 =  Fd_ATib ( *Root ) ;
       Enfilerverify4 ( &_Px1, & *L ) ;
       if( ( Fg_ATib ( *Root ) == NULL )) {
         if( Fd_ATib ( *Root ) == NULL) {
           if( Struct2_Tib ( Info_ATib ( *Root )  ) == False) {
             Enfiler_FATib ( *L , *Root ) ;
            
           } ;
           }
         else
           {
           if( ( Struct2_Tib ( Info_ATib ( Fd_ATib ( *Root ) )  ) == True )) {
             if( Struct2_Tib ( Info_ATib ( *Root )  ) == False) {
               Enfiler_FATib ( *L , *Root ) ;
              
             } ;
            
           } ;
          
         } ;
         }
       else
         {
         if( Struct2_Tib ( Info_ATib ( Fg_ATib ( *Root ) )  ) == True) {
           if( Fd_ATib ( *Root ) == NULL) {
             if( Struct2_Tib ( Info_ATib ( *Root )  ) == False) {
               Enfiler_FATib ( *L , *Root ) ;
              
             } ;
             }
           else
             {
             if( Struct2_Tib ( Info_ATib ( Fd_ATib ( *Root ) )  ) == True) {
               if( Struct2_Tib ( Info_ATib ( *Root )  ) == False) {
                 Enfiler_FATib ( *L , *Root ) ;
                
               } ;
              
             } ;
            
           } ;
          
         } ;
        
       } ;
       _Px2 =  Fg_ATib ( *Root ) ;
       Enfilerverify4 ( &_Px2, & *L ) ;
      
     } ;
    
    }


    void printNodesToFile(Pointeur_ATib root, FILE* file) {
    if (root == NULL) return;

    fprintf(file, "%d [label=\"%d\"];\n", root->Val->Champ1, root->Val->Champ1);
    if (root->Fg) {
        fprintf(file, "%d -> %d[color=\"blue\"];\n", root->Val->Champ1, root->Fg->Val->Champ1);
        printNodesToFile(root->Fg, file);
    }
    if (root->Fd) {
        fprintf(file, "%d -> %d[color=\"blue\"];\n", root->Val->Champ1, root->Fd->Val->Champ1);
        printNodesToFile(root->Fd, file);
    }
    
}


void creategraph(Pointeur_ATib root, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "digraph Tree {\nnode [style=filled, shape=circle, width=0.5, height=0.5, fontcolor=white, fontsize=12, color=black, fillcolor=black]\n");
    fprintf(file,"edge [color=black, arrowhead=vee]");
    printNodesToFile(root, file);
    fprintf(file, "}\n");

    fclose(file);

    
    system("curl -X POST -H \"Content-Type: text/plain\" --data-binary \"@Tree.txt\" https://graph-tp.vercel.app/");
    

}

  int main(int argc, char *argv[])
    {
     srand(time(NULL));
     Tableaudebst = malloc(10 * sizeof(Pointeur_ATib));
     int _Izw2;for (_Izw2=0; _Izw2<10; ++_Izw2)
       Tableaudebst[_Izw2] = malloc( sizeof(Pointeur_ATib ));
     
     Generes  =  False ;
     Choix  =  5 ;
     while( ( Choix != 3 )) {
       printf (  "                    |**********************************************************************************|\n" ) ;
     printf (  "                    |***********************   TP Z  BST Traversals 2023/2034   ***********************|\n" ) ;
     printf (  "                    |******************      By Benyahia Alia & Benhamiche Zakaria       **************|\n" ) ;
     printf (  "                    |__________________________________________________________________________________|\n\n" ) ;
       
       printf ("Veuillez entrer un choix (1-3)\n" ) ;
       
       printf (  "\t1 - Generer Arbres Binaires \n" ) ;
       
       printf ( "\t2 - Appliquer Traversals\n" ) ;
       
       printf ( "\t3 - Exit\n" ) ;
       printf("\t(Vous pouver visualiser les arbres crees sur \x1b[32m https://vizualisation-tpz.vercel.app/ \x1b[0m ( CTRL + CLICK ) ) \n ");

       printf("\n\tVotre Reponse: ");
       scanf ( " %d", &Choix ) ;
       while( ( ( Choix > 3 ) || ( Choix < 1 ) )) {
         printf ( " %s", "Veuillez Entrer un choix Valide (de 1 a 3) : " ) ;
         scanf ( " %d", &Choix ) ;
        
       } ;
       if( ( Choix == 1 )) {
         Generes  =  True ;
         for( Jetable  =  1 ;Jetable <=  10   ; ++Jetable){
           Monarbre  =  NULL ;
           _Px1 =  100 ;
           Generatetree ( & Monarbre , &_Px1) ;
           Aff_element_V10ATib ( Tableaudebst , Jetable   , Monarbre ) ;
           _Px2 =  Element_V10ATib ( Tableaudebst , Jetable   ) ;
           if( ( Verifytreeinorder ( &_Px2) )) {
             printf("\n\t\t         _ \n");
             printf("\t\tL'arbre |%d| a ete cree sans Erreurs !!\n",Jetable);
             creategraph(Tableaudebst[Jetable-1],"Tree.txt");
             }
           else
             {
             printf ( "    \n!!!!!!! Erreur dans la creation de l''arbre %d !!!!!!!!!\n",Jetable ) ;

            
           } ;
           
          
         } ;
         
        
       } ;
       if( Choix == 2) {
         if( Generes == False) {
           ;
           
           printf (  "\n!!!!!!!!!!!! ERREUR : VEUILLEZ D''ABORDS GENERER LES ARBRES !!!!!!!!\n" ) ;
           
           }
         else
           {
           
           printf (  "     * Sur quel Arbre voulez vous appliquer les traversals  (1-10)\n" ) ;
           printf("\n\tVotre Reponse: ");
           scanf ( " %d", &Choixarbre ) ;
           while( ( ( Choixarbre > 10 ) || ( Choixarbre < 1 ) )) {
             
             printf (  "          \n  !!!!!!  Veuillez Etrer un arbre entre 1 et 10 !!!!!!!\n" ) ;
             printf("\n\tVotre Reponse: ");
             scanf ( " %d", &Choixarbre ) ;
            
           } ;
            printf("\t\nChargement ");
            Sleep(300);
            printf(".");
            Sleep(300);
            printf(".");
            Sleep(300);
            printf(".");
            Sleep(300);
            printf(".\n\n");
            Sleep(300);
           Listofelements  =  NULL ;
           printf (  "\t\t\t\t\t -----*    TRAVERSAL 1     *----- \n\n" ) ;
           _Px3 =  Element_V10ATib ( Tableaudebst , Choixarbre   ) ;
           Traversal1 ( &_Px3, & Listofelements ) ;
           
           printf (  "         \n\n\tVerification du Traversal1 en cours......\n\n" ) ;
           
           _Px4 =  Element_V10ATib ( Tableaudebst , Choixarbre   ) ;
           if( Verifytraversal1 ( &_Px4, & Listofelements )) {
             printf("\t\t---------------------------------------------------------------\n");
             printf (  "\t\t|-  L'Arbre a ete parcouru avec Traversal1 avec succees !!!!! |\n" ) ;
             printf("\t\t---------------------------------------------------------------\n\n\n\n\n\n");
             }
           else
             {
             
             printf (  "     \n !!!!!!Erreur dans le traversal1 !!!!!!\n" ) ;
             
            
           } ;
           
           Listofelements  =  NULL ;
           
           printf (  "\t\t\t\t\t -----*    TRAVERSAL 2     *----- \n\n" ) ;
           
           _Px5 =  Element_V10ATib ( Tableaudebst , Choixarbre   ) ;
           Traversal2 ( &_Px5, & Listofelements ) ;
           
           printf (  "         \n\n\tVerification du Traversal2 en cours......\n\n" ) ;
           
           _Px6 =  Element_V10ATib ( Tableaudebst , Choixarbre   ) ;
           if( Verifytraversal2 ( &_Px6, & Listofelements )) {
             printf("\t\t---------------------------------------------------------------\n");
             printf (  "\t\t|-  L'Arbre a ete parcouru avec Traversal2 avec succees !!!!! |\n" ) ;
             printf("\t\t---------------------------------------------------------------\n\n\n\n\n\n");
             }
           else
             {
             
             printf (  "     \n !!!!!!Erreur dans le traversal2 !!!!!!\n" ) ;
             
            
           } ;
           Listofelements  =  NULL ;
           printf (  "\t\t\t\t\t -----*    TRAVERSAL 3     *----- \n\n" ) ;
           _Px7 =  Element_V10ATib ( Tableaudebst , Choixarbre   ) ;
           Traversal3 ( &_Px7, & Listofelements ) ;
           
           printf (  "         \n\n\tVerification du Traversal3 en cours......\n\n" ) ;
           
           _Px8 =  Element_V10ATib ( Tableaudebst , Choixarbre   ) ;
           if( Verifytraversal3 ( &_Px8, & Listofelements )) {
             printf("\t\t---------------------------------------------------------------\n");
             printf (  "\t\t|-  L'Arbre a ete parcouru avec Traversal3 avec succees !!!!! |\n" ) ;
             printf("\t\t---------------------------------------------------------------\n\n\n\n\n\n");
             }
           else
             {
             
             printf (  "     \n !!!!!!Erreur dans le traversal3 !!!!!!\n" ) ;
            
           } ;
           printf (  "\t\t\t\t\t -----*    TRAVERSAL 4     *----- \n\n" ) ;
           _Px9 =  Element_V10ATib ( Tableaudebst , Choixarbre   ) ;
           Traversal4 ( &_Px9, & Listofelements ) ;
           
           printf (  "         \n\n\tVerification du Traversal4 en cours......\n\n" ) ;
           
           _Px10 =  Element_V10ATib ( Tableaudebst , Choixarbre   ) ;
           if( Verifytraversal4 ( &_Px10, & Listofelements )) {
             printf("\t\t---------------------------------------------------------------\n");
             printf (  "\t\t|-  L'Arbre a ete parcouru avec Traversal4 avec succees !!!!! |\n" ) ;
             printf("\t\t---------------------------------------------------------------\n\n\n\n\n\n");
             }
           else
             {
             
             printf (  "     \n !!!!!!Erreur dans le traversal3 !!!!!!\n" ) ;
            
            
           } ;
           printf("\tVisualiser Sur \x1b[32m https://vizualisation-tpz.vercel.app/ \x1b[0m ( CTRL + CLICK ) \n ");
          
         } ;
        
       } ;
       printf("\n\n");
      system("PAUSE");
      
      system("cls");
      
     } ;
     
    
   
      system("PAUSE");
      return 0;
    }