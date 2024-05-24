
   SOIENT
       Monarbre : ARB DE ( ENTIER , BOOLEEN ) ;
       L UNE FILE DE ENTIER ;
       B : BOOLEEN ;
       Choix : ENTIER ;
       Generes : BOOLEEN ;
       Tableaudebst UN VECTEUR ( 10 ) DE ARB DE ( ENTIER , BOOLEEN ) ;
       Choixarbre : ENTIER ;
       Jetable : ENTIER ;
       Listofelements UNE LISTE DE ENTIER ;
      /****************************                         FONCTION ***********************************/
       Verifytreeinorder : FONCTION ( BOOLEEN ) ;
       Search : FONCTION ( BOOLEEN ) ;
       Verifytraversal1 : FONCTION ( BOOLEEN ) ;
       Verifytraversal2 : FONCTION ( BOOLEEN ) ;
       Verifytraversal3 : FONCTION ( BOOLEEN ) ;
       Verifytraversal4 : FONCTION ( BOOLEEN ) ;
      /****************************                     Procedure **********************************/
       Inordrepush : ACTION ;
       Afficherarbre : ACTION ;
       Inserer : ACTION ;
       Traversal1 : ACTION ;
       Traversal2 : ACTION ;
       Traversal3 : ACTION ;
       Traversal4 : ACTION ;
       Resettree : ACTION ;
       Generatetree : ACTION ;
       Enqueueleaves : ACTION ;
       Enfilerinordre : ACTION ;
       Enfilerinordre3 : ACTION ;
       Ajouteralafin : ACTION ;
       Enqueueleavesrev : ACTION ;
       Enfilerverify2 : ACTION ;
       Enfilerverify4 : ACTION ;
       Menu : ACTION ;
       etiquette:action;
      
   DEBUT
       appel etiquette;
       Generes := FAUX ;
       Choix := 5 ;
       TANTQUE ( Choix <> 3 )
           APPEL Menu ;
           LIRE ( Choix ) ;
           TANTQUE ( ( Choix > 3 ) OU ( Choix < 1 ) )
               ECRIRE ( 'Veuillez Entrer un choix Valide (de 1 a 3)' ) ;
               LIRE ( Choix ) ;
              
           FTQ ;
           SI ( Choix = 1 )
               Generes := VRAI ;
               POUR Jetable := 1 , 10 , 1
                   Monarbre := NIL ;
                   appel generateTree(monarbre,100);
                   AFF_ELEMENT ( Tableaudebst [ Jetable ] , Monarbre ) ;
                   SI ( Verifytreeinorder ( ELEMENT ( Tableaudebst [ Jetable ] ) ) )
                       ECRIRE ( '      ' ) ;
                       ECRIRE ( '      ' ) ;
                       ECRIRE ( '**************   L''arbre   *************' ) ;
                       ECRIRE ( Jetable ) ;
                       ECRIRE ( '**********   a ete créé avec succés   ***********' ) ;
                       ECRIRE ( '      ' ) ;
                       ECRIRE ( '      ' ) ;
                      
                   SINON
                       ECRIRE ( '      ' ) ;
                       ECRIRE ( '    !!!!!!! Erreur dans la creation de l''arbre !!!!!!!!!' ) ;
                       ECRIRE ( '      ' ) ;
                      
                   FSI ;
                  
               FPOUR ;
              
           FSI ;
           SI Choix = 2
               SI Generes = FAUX
                   ;
                   ECRIRE ( '' ) ;
                   ECRIRE ( '!!!!!!!!!!!! ERREUR : VEUILLEZ D''ABORDS GENERER LES ARBRES !!!!!!!!' ) ;
                   ECRIRE ( '' ) ;
                  
               SINON
                   ECRIRE ( '' ) ;
                   ECRIRE ( '' ) ;
                   ECRIRE ( '     * Sur quel Arbre voulez vous appliquer les traversals ? (1-10)' ) ;
                   LIRE ( Choixarbre ) ;
                   TANTQUE ( ( Choixarbre > 10 ) OU ( Choixarbre < 1 ) )
                       ECRIRE ( '' ) ;
                       ECRIRE ( '            !!!!!!  Veuillez Etrer un arbre entre 1 et 10 !!!!!!!' ) ;
                       ECRIRE ( '' ) ;
                       LIRE ( Choixarbre ) ;
                      
                   FTQ ;
                   ECRIRE ( '       Chargement en cours...' ) ;
                   Listofelements := NIL ;
                   ECRIRE ( '             -- TRAVERSAL 1 --              ' ) ;
                   APPEL Traversal1 ( ELEMENT ( Tableaudebst [ Choixarbre ] ) , Listofelements ) ;
                   ECRIRE ( '' ) ;
                   ECRIRE ( '           Verification du Traversal1 en cours......' ) ;
                   ECRIRE ( '' ) ;
                   SI Verifytraversal1 ( ELEMENT ( Tableaudebst [ Choixarbre ] ) , Listofelements )
                       ECRIRE ( '' ) ;
                       ECRIRE ( '          L''Arbre a ete parcouru avec Traversal1 avec succees !!!!!' ) ;
                       ECRIRE ( '' ) ;
                      
                   SINON
                       ECRIRE ( '' ) ;
                       ECRIRE ( '      !!!!!!Erreur dans le traversal1 !!!!!!' ) ;
                       ECRIRE ( '' ) ;
                      
                   FSI ;
                   Listofelements := NIL ;
                   ECRIRE ( '' ) ;
                   ECRIRE ( '             -- TRAVERSAL 2 --              ' ) ;
                   ECRIRE ( '' ) ;
                   APPEL Traversal2 ( ELEMENT ( Tableaudebst [ Choixarbre ] ) , Listofelements ) ;
                   ECRIRE ( '' ) ;
                   ECRIRE ( '           Verification du Traversal2 en cours......' ) ;
                   ECRIRE ( '' ) ;
                   SI Verifytraversal2 ( ELEMENT ( Tableaudebst [ Choixarbre ] ) , Listofelements )
                       ECRIRE ( '' ) ;
                       ECRIRE ( '          L''Arbre a ete parcouru avec Traversal2 avec succees !!!!!' ) ;
                       ECRIRE ( '' ) ;
                      
                   SINON
                       ECRIRE ( '' ) ;
                       ECRIRE ( '      !!!!!!Erreur dans le traversal2 !!!!!!' ) ;
                       ECRIRE ( '' ) ;
                      
                   FSI ;
                   Listofelements := NIL ;
                   ECRIRE ( '             -- TRAVERSAL 3 --              ' ) ;
                   APPEL Traversal3 ( ELEMENT ( Tableaudebst [ Choixarbre ] ) , Listofelements ) ;
                   ECRIRE ( '' ) ;
                   ECRIRE ( '           Verification du Traversal3 en cours......' ) ;
                   ECRIRE ( '' ) ;
                   SI Verifytraversal3 ( ELEMENT ( Tableaudebst [ Choixarbre ] ) , Listofelements )
                       ECRIRE ( '' ) ;
                       ECRIRE ( '          L''Arbre a ete parcouru avec Traversal3 avec succees !!!!!' ) ;
                       ECRIRE ( '' ) ;
                      
                   SINON
                       ECRIRE ( '' ) ;
                       ECRIRE ( '      !!!!!!Erreur dans le traversal3 !!!!!!' ) ;
                      
                   FSI ;
                   ECRIRE ( '             -- TRAVERSAL 4 --              ' ) ;
                   APPEL Traversal4 ( ELEMENT ( Tableaudebst [ Choixarbre ] ) , Listofelements ) ;
                   ECRIRE ( '' ) ;
                   ECRIRE ( '           Verification du Traversal4 en cours......' ) ;
                   ECRIRE ( '' ) ;
                   SI Verifytraversal4 ( ELEMENT ( Tableaudebst [ Choixarbre ] ) , Listofelements )
                       ECRIRE ( '' ) ;
                       ECRIRE ( '          L''Arbre a ete parcouru avec Traversal4 avec succees !!!!!' ) ;
                       ECRIRE ( '' ) ;
                      
                   SINON
                       ECRIRE ( '' ) ;
                       ECRIRE ( '      !!!!!!Erreur dans le traversal4 !!!!!!' ) ;
                      
                   FSI ;
                  
               FINSI ;
              
           FINSI ;
          
       FTQ ;
      
   FIN
  { 
   }
  { 
   }
  /*************   Menu *************/
   ACTION Menu DEBUT
       ECRIRE ( '' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'Veuillez entrer un choix (1-3)' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( '      1 - Génerer Arbres Binaires ' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( '      2 - Appliquer Traversals' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( '      3 - Exit' ) ;
       ECRIRE ( '' ) ;
      
   FIN
   /*************************************/
   action etiquette
   debut
   ECRIRE ( '|' ) ;
       ECRIRE ( '                    |*************************************************************|' ) ;
       ECRIRE ( '                    |********TP Z  BST Traversals 2023/2034*************|' ) ;
       ECRIRE ( '                    |******* By Benyahia Alia & Benhamiche Zakaria *****|' ) ;
       ECRIRE ( '                    |________________________________________|' ) ;
       fin
  /****************************                   Fonction affichage *************************/
   ACTION Afficherarbre ( R )
   SOIT
       R UN ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI R <> NIL
           APPEL Afficherarbre ( FG ( R ) ) ;
           ECRIRE ( STRUCT ( INFO ( R ) , 1 ) ) ;
           APPEL Afficherarbre ( FD ( R ) ) ;
          
       FSI
   FIN
  { 
   }
  /*************************      Verification Creation BST *************************/
   FONCTION Verifytreeinorder ( Root ) : BOOLEEN
   SOIT
       Root UN ARB DE ( ENTIER , BOOLEEN ) ;
       P UNE PILE DE ( ENTIER , BOOLEEN ) ;
       A , B DES ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       APPEL Inordrepush ( Root , P ) ;
       Verifytreeinorder := VRAI ;
       SI NON PILEVIDE ( P )
           DEPILER ( P , A ) ;
          
       FSI ;
       TQ ( NON ( PILEVIDE ( P ) ) )
           DEPILER ( P , B ) ;
           SI STRUCT ( A , 1 ) < STRUCT ( B , 1 ) :
               Verifytreeinorder := FAUX ;
              
           FSI ;
           A := B ;
          
       FTQ
   FIN
  { 
   }
  /****************************       Push noeuds Inordre ****************************/
   ACTION Inordrepush ( Root , P )
   SOIT
       Root UN ARB DE ( ENTIER , BOOLEEN ) ;
       P UNE PILE DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI Root <> NIL
           APPEL Inordrepush ( FG ( Root ) , P ) ;
           EMPILER ( P , INFO ( Root ) ) ;
           APPEL Inordrepush ( FD ( Root ) , P ) ;
          
       FSI
   FIN
  { 
   }
  /*************************      Renitialiser Noeuds visités ************************/
   ACTION Resettree ( R )
   SOIT
       R UN ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI R <> NIL :
           APPEL Resettree ( FG ( R ) ) ;
           AFF_STRUCT ( INFO ( R ) , 2 , FAUX ) ;
           APPEL Resettree ( FD ( R ) ) ;
          
       FSI ;
      
   FIN
  { 
   }
  /*************************      Rechercher noeud dans BST ************************/
   FONCTION Search ( Root , Value ) : BOOLEEN
   SOIT
       Root UN ARB DE ( ENTIER , BOOLEEN ) ;
       Value UN ENTIER ;
      
   DEBUT
       SI Root <> NIL
           SI Value = STRUCT ( INFO ( Root ) , 1 )
               Search := VRAI ;
              
           SINON
               SI Value > STRUCT ( INFO ( Root ) , 1 )
                   Search := Search ( FD ( Root ) , Value ) ;
                  
               SINON
                   Search := Search ( FG ( Root ) , Value ) ;
                  
               FSI ;
              
           FSI ;
          
       SINON
           Search := FAUX ;
          
       FSI ;
      
   FIN
  { 
   }
  /*************************       Inserer Noeud dans BST *************************/
   ACTION Inserer ( Root , Value )
   SOIENT
       Root UN ARB DE ( ENTIER , BOOLEEN ) ;
       Value UN ENTIER ;
       P UN ARB DE ( ENTIER , BOOLEEN ) ;
       New UN ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI Root = NIL :
           CREERNOEUD ( Root ) ;
           INIT_STRUCT ( New , [ Value , FAUX ] ) ;
           AFF_INFO ( Root , New ) ;
          
       SINON
           SI ( ( Value < STRUCT ( INFO ( Root ) , 1 ) ) ET ( FG ( Root ) = NIL ) ) :
               CREERNOEUD ( P ) ;
               INIT_STRUCT ( New , [ Value , FAUX ] ) ;
               AFF_INFO ( P , New ) ;
               AFF_PERE ( P , Root ) ;
               AFF_FG ( Root , P ) ;
              
           SINON
               SI ( ( Value >= STRUCT ( INFO ( Root ) , 1 ) ) ET ( FD ( Root ) = NIL ) ) :
                   CREERNOEUD ( P ) ;
                   INIT_STRUCT ( New , [ Value , FAUX ] ) ;
                   AFF_INFO ( P , New ) ;
                   AFF_PERE ( P , Root ) ;
                   AFF_FD ( Root , P ) ;
                  
               SINON
                   SI ( ( Value < STRUCT ( INFO ( Root ) , 1 ) ) ET ( FG ( Root ) <> NIL ) )
                       APPEL Inserer ( FG ( Root ) , Value ) ;
                      
                   SINON
                       APPEL Inserer ( FD ( Root ) , Value ) ;
                      
                   FSI
               FSI
           FSI
       FSI
   FIN
  { 
   }
  /***************************GGGenerer ARBRE BST ***************************/
   ACTION Generatetree ( Root , N )
   SOIT
       Root UN ARB DE ( ENTIER , BOOLEEN ) ;
       N UN ENTIER ;
       I UN ENTIER ;
       A UN ENTIER ;
      
   DEBUT
       POUR I := 1 , N , 1
           A := ALEANOMBRE ( 300 ) ;
           TANTQUE Search ( Root , A ) :
               A := ALEANOMBRE ( 300 ) ;
              
           FTQ ;
           APPEL Inserer ( Root , A ) ;
          
       FPOUR ;
      
   FIN
  { 
   }
  /***********************TTTTTraversal 1 BB-LR-Bottom To Top ***********************/
   ACTION Traversal1 ( Root , L )
   SOIT
       Root UN ARB DE ( ENTIER , BOOLEEN ) ;
       Stack UNE PILE DE ARB DE ( ENTIER , BOOLEEN ) ;
       Q UN ARB DE ( ENTIER , BOOLEEN ) ;
       A UN ENTIER ;
       L UNE LISTE DE ENTIER ;
      
   DEBUT
       Q := Root ;
       SI Q = NIL :
           ECRIRE ( 'L arbre est vide' ) ;
          
       SINON
           TANTQUE ( Q <> NIL )
               SI ( ( FG ( Q ) <> NIL ) ET ( FD ( Q ) <> NIL ) ) :
                   EMPILER ( Stack , FD ( Q ) )
               FSI ;
               SI ( FG ( Q ) <> NIL )
                   Q := FG ( Q ) ;
                  
               SINON
                   SI ( FD ( Q ) <> NIL )
                       Q := FD ( Q ) ;
                      
                   FSI ;
                  
               FSI ;
               SI ( ( FG ( Q ) = NIL ) ET ( FD ( Q ) = NIL ) )
                   TANTQUE ( Q <> NIL )
                       SI ( STRUCT ( INFO ( Q ) , 2 ) = FAUX )
                           ECRIRE ( STRUCT ( INFO ( Q ) , 1 ) ) ;
                           APPEL Ajouteralafin ( L , STRUCT ( INFO ( Q ) , 1 ) ) ;
                           AFF_STRUCT ( INFO ( Q ) , 2 , VRAI ) ;
                           Q := PERE ( Q ) ;
                          
                       SINON
                           Q := NIL ;
                          
                       FSI
                   FTQ ;
                   SI ( NON PILEVIDE ( Stack ) )
                       DEPILER ( Stack , Q ) ;
                      
                   FSI ;
                  
               FSI ;
              
           FTQ
       FSI ;
       APPEL Resettree ( Root ) ;
      
   FIN
  { 
   }
  /*********************     Verify Traversal 1 ******************************/
   FONCTION Verifytraversal1 ( Root , L1 ) : BOOLEEN ;
   SOIENT
       Root UN ARB DE ( ENTIER , BOOLEEN ) ;
       L2 UNE LISTE DE ENTIER ;
       Q UNE FILE DE ENTIER ;
       P UN ENTIER ;
       L1 UNE LISTE DE ENTIER ;
       Egaux UN BOOLEEN ;
      
   DEBUT
       CREERFILE ( Q ) ;
       Egaux := VRAI ;
       L2 := NIL ;
       APPEL Enfilerinordre ( Root , Q ) ;
       TANTQUE ( NON FILEVIDE ( Q ) )
           DEFILER ( Q , P ) ;
           APPEL Ajouteralafin ( L2 , P ) ;
          
       FTQ ;
       TANTQUE ( ( L2 <> NIL ) ET Egaux )
           SI ( VALEUR ( L1 ) <> VALEUR ( L2 ) )
               Egaux := FAUX ;
              
           FSI ;
           L2 := SUIVANT ( L2 ) ;
           L1 := SUIVANT ( L1 ) ;
          
       FTQ ;
       Verifytraversal1 := Egaux ;
      
   FIN
  /**************************************************************/
   ACTION Enfilerinordre ( Root , Q ) ;
   SOIENT
       Q UNE FILE DE ENTIER ;
       Root UN ARB DE ( ENTIER , BOOLEEN ) ;
       P UN ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI ( Root <> NIL )
           APPEL Enfilerinordre ( FG ( Root ) , Q ) ;
           SI ( ( FG ( Root ) = NIL ) ET ( FD ( Root ) = NIL ) )
               P := Root ;
               TANTQUE P <> NIL
                   ENFILER ( Q , STRUCT ( INFO ( P ) , 1 ) ) ;
                   P := PERE ( P ) ;
                  
               FTQ ;
              
           FSI ;
           APPEL Enfilerinordre ( FD ( Root ) , Q ) ;
          
       FSI ;
      
   FIN
  /***********************       Traversal 2  ***********************/
   ACTION Traversal2 ( Root , L )
   SOIT
       Root UN ARB DE ( ENTIER , BOOLEEN ) ;
       Q UNE FILE DE ARB DE ( ENTIER , BOOLEEN ) ;
       P UN ARB DE ( ENTIER , BOOLEEN ) ;
       L UNE LISTE DE ENTIER ;
      
   DEBUT
       CREERFILE ( Q ) ;
       APPEL Enqueueleaves ( Root , Q ) ;
       TANTQUE NON FILEVIDE ( Q )
           ;
           DEFILER ( Q , P ) ;
           AFF_STRUCT ( INFO ( P ) , 2 , VRAI ) ;
           ECRIRE ( STRUCT ( INFO ( P ) , 1 ) ) ;
           APPEL Ajouteralafin ( L , STRUCT ( INFO ( P ) , 1 ) ) ;
           SI PERE ( P ) <> NIL
               SI ( FG ( PERE ( P ) ) = NIL )
                   SI FD ( PERE ( P ) ) = NIL
                       ENFILER ( Q , PERE ( P ) ) ;
                      
                   SINON
                       SI ( STRUCT ( INFO ( FD ( PERE ( P ) ) ) , 2 ) = VRAI )
                           ENFILER ( Q , PERE ( P ) ) ;
                          
                       FSI ;
                      
                   FSI ;
                  
               SINON
                   SI STRUCT ( INFO ( FG ( PERE ( P ) ) ) , 2 ) = VRAI
                       SI FD ( PERE ( P ) ) = NIL
                           ENFILER ( Q , PERE ( P ) ) ;
                          
                       SINON
                           SI STRUCT ( INFO ( FD ( PERE ( P ) ) ) , 2 ) = VRAI
                               ENFILER ( Q , PERE ( P ) ) ;
                              
                           FSI ;
                          
                       FSI ;
                      
                   FSI ;
                  
               FSI ;
              
           FSI ;
          
       FTQ ;
       APPEL Resettree ( Root ) ;
      
   FIN
  /********************      Enqueue leaves **********************/
   ACTION Enqueueleaves ( Root , Q ) ;
   SOIT
       Root UN ARB DE ( ENTIER , BOOLEEN ) ;
       Q : FILE DE ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI Root <> NIL
           APPEL Enqueueleaves ( FG ( Root ) , Q ) ;
           SI ( FD ( Root ) = NIL ) ET ( FG ( Root ) = NIL )
               ENFILER ( Q , Root ) ;
              
           FSI ;
           APPEL Enqueueleaves ( FD ( Root ) , Q ) ;
          
       FSI ;
      
   FIN
  /******************       Verify Traversal 2    ****************************/
   FONCTION Verifytraversal2 ( Root , List ) : BOOLEEN
   SOIENT
       Root UN ARB DE ( ENTIER , BOOLEEN ) ;
       Temp UNE FILE DE ARB DE ( ENTIER , BOOLEEN ) ;
       L UNE FILE DE ENTIER ;
       Egaux UN BOOLEEN ;
       A UN ENTIER ;
       List UNE LISTE DE ENTIER ;
       P UN ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       CREERFILE ( L ) ;
       CREERFILE ( Temp ) ;
       Egaux := VRAI ;
       TANTQUE ( STRUCT ( INFO ( Root ) , 2 ) ) = FAUX
           APPEL Enfilerverify2 ( Root , Temp ) ;
          /* Enfile les noeuds consideres comme feuille */
           TANTQUE NON FILEVIDE ( Temp )
               DEFILER ( Temp , P ) ;
               AFF_STRUCT ( INFO ( P ) , 2 , VRAI ) ;
              /* Les mets a visited*/
               ENFILER ( L , STRUCT ( INFO ( P ) , 1 ) ) ;
              
           FTQ ;
          
       FTQ ;
       APPEL Resettree ( Root ) ;
       TANTQUE NON FILEVIDE ( L )
           DEFILER ( L , A ) ;
           SI VALEUR ( List ) <> A
               Egaux := FAUX ;
              
           FSI ;
           List := SUIVANT ( List ) ;
          
       FTQ ;
       Verifytraversal2 := Egaux ;
       APPEL Resettree ( Root ) ;
      
   FIN
  /*************************************/
   ACTION Enfilerverify2 ( Root , L )
   SOIENT
       Root UN ARB DE ( ENTIER , BOOLEEN ) ;
       L UNE FILE DE ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI Root <> NIL
           APPEL Enfilerverify2 ( FG ( Root ) , L ) ;
           SI ( FG ( Root ) = NIL )
               SI FD ( Root ) = NIL
                   SI STRUCT ( INFO ( Root ) , 2 ) = FAUX
                       ENFILER ( L , Root ) ;
                      
                   FSI ;
                  
               SINON
                   SI ( STRUCT ( INFO ( FD ( Root ) ) , 2 ) = VRAI )
                       SI STRUCT ( INFO ( Root ) , 2 ) = FAUX
                           ENFILER ( L , Root ) ;
                          
                       FSI ;
                      
                   FSI ;
                  
               FSI ;
              
           SINON
               SI STRUCT ( INFO ( FG ( Root ) ) , 2 ) = VRAI
                   SI FD ( Root ) = NIL
                       SI STRUCT ( INFO ( Root ) , 2 ) = FAUX
                           ENFILER ( L , Root ) ;
                          
                       FSI ;
                      
                   SINON
                       SI STRUCT ( INFO ( FD ( Root ) ) , 2 ) = VRAI
                           SI STRUCT ( INFO ( Root ) , 2 ) = FAUX
                               ENFILER ( L , Root ) ;
                              
                           FSI ;
                          
                       FSI ;
                      
                   FSI ;
                  
               FSI ;
              
           FSI ;
           APPEL Enfilerverify2 ( FD ( Root ) , L ) ;
          
       FSI ;
      
   FIN
  /**********************************************************************/
   ACTION Ajouteralafin ( Head , Val ) ;
   SOIENT
       Head UNE LISTE DE ENTIER ;
       Val UN ENTIER ;
       P , Q DES LISTE DE ENTIER ;
       Exist : BOOLEEN ;
      
   DEBUT
       Exist := FAUX ;
       SI Head = NIL
           ALLOUER ( Head ) ;
           AFF_VAL ( Head , Val ) ;
          
       SINON
           P := Head ;
           TANTQUE ( ( SUIVANT ( P ) <> NIL ) ET ( NON Exist ) )
               SI ( Val = VALEUR ( P ) )
                   Exist := VRAI ;
                  
               FSI ;
               P := SUIVANT ( P ) ;
              
           FTQ ;
           SI ( NON Exist )
               ALLOUER ( Q ) ;
               AFF_VAL ( Q , Val ) ;
               AFF_ADR ( P , Q ) ;
              
           FINSI ;
          
       FINSI ;
      
   FIN
  /***********************************     Traversal 3       ******************************/
   ACTION Traversal3 ( Root , L )
   SOIT
       Root UN ARB DE ( ENTIER , BOOLEEN ) ;
       Stack UNE PILE DE ARB DE ( ENTIER , BOOLEEN ) ;
       Q UN ARB DE ( ENTIER , BOOLEEN ) ;
       A UN ENTIER ;
       L UNE LISTE DE ENTIER ;
      
   DEBUT
       Q := Root ;
       SI Q = NIL :
           ECRIRE ( 'L arbre est vide' ) ;
          
       SINON
           TANTQUE ( Q <> NIL )
               SI ( ( FD ( Q ) <> NIL ) ET ( FG ( Q ) <> NIL ) ) :
                   EMPILER ( Stack , FG ( Q ) )
               FSI ;
               SI ( FD ( Q ) <> NIL )
                   Q := FD ( Q ) ;
                  
               SINON
                   SI ( FG ( Q ) <> NIL )
                       Q := FG ( Q ) ;
                      
                   FSI ;
                  
               FSI ;
               SI ( ( FG ( Q ) = NIL ) ET ( FD ( Q ) = NIL ) )
                   TANTQUE ( Q <> NIL )
                       SI ( STRUCT ( INFO ( Q ) , 2 ) = FAUX )
                           ECRIRE ( STRUCT ( INFO ( Q ) , 1 ) ) ;
                           APPEL Ajouteralafin ( L , STRUCT ( INFO ( Q ) , 1 ) ) ;
                           AFF_STRUCT ( INFO ( Q ) , 2 , VRAI ) ;
                           Q := PERE ( Q ) ;
                          
                       SINON
                           Q := NIL ;
                          
                       FSI
                   FTQ ;
                   SI ( NON PILEVIDE ( Stack ) )
                       DEPILER ( Stack , Q ) ;
                      
                   FSI ;
                  
               FSI ;
              
           FTQ
       FSI ;
       APPEL Resettree ( Root ) ;
      
   FIN
  { 
   }
  /*********************     Verify Traversal 3 ******************************/
   FONCTION Verifytraversal3 ( Root , L1 ) : BOOLEEN ;
   SOIENT
       Root UN ARB DE ( ENTIER , BOOLEEN ) ;
       L2 UNE LISTE DE ENTIER ;
       Q UNE FILE DE ENTIER ;
       P UN ENTIER ;
       L1 UNE LISTE DE ENTIER ;
       Egaux UN BOOLEEN ;
      
   DEBUT
       CREERFILE ( Q ) ;
       Egaux := VRAI ;
       L2 := NIL ;
       APPEL Enfilerinordre3 ( Root , Q ) ;
       TANTQUE ( NON FILEVIDE ( Q ) )
           DEFILER ( Q , P ) ;
           APPEL Ajouteralafin ( L2 , P ) ;
          
       FTQ ;
       TANTQUE ( ( L2 <> NIL ) ET Egaux )
           SI ( VALEUR ( L1 ) <> VALEUR ( L2 ) )
               Egaux := FAUX ;
              
           FSI ;
           L2 := SUIVANT ( L2 ) ;
           L1 := SUIVANT ( L1 ) ;
          
       FTQ ;
       Verifytraversal3 := Egaux ;
      
   FIN
  /**************************************************************/
   ACTION Enfilerinordre3 ( Root , Q ) ;
   SOIENT
       Q UNE FILE DE ENTIER ;
       Root UN ARB DE ( ENTIER , BOOLEEN ) ;
       P UN ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI ( Root <> NIL )
           APPEL Enfilerinordre3 ( FD ( Root ) , Q ) ;
           SI ( ( FG ( Root ) = NIL ) ET ( FD ( Root ) = NIL ) )
               P := Root ;
               TANTQUE P <> NIL
                   ENFILER ( Q , STRUCT ( INFO ( P ) , 1 ) ) ;
                   P := PERE ( P ) ;
                  
               FTQ ;
              
           FSI ;
           APPEL Enfilerinordre3 ( FG ( Root ) , Q ) ;
          
       FSI ;
      
   FIN
  /***********************       Traversal 4  ***********************/
   ACTION Traversal4 ( Root , L )
   SOIT
       Root UN ARB DE ( ENTIER , BOOLEEN ) ;
       Q UNE FILE DE ARB DE ( ENTIER , BOOLEEN ) ;
       P UN ARB DE ( ENTIER , BOOLEEN ) ;
       L UNE LISTE DE ENTIER ;
      
   DEBUT
       CREERFILE ( Q ) ;
       APPEL Enqueueleavesrev ( Root , Q ) ;
       TANTQUE NON FILEVIDE ( Q )
           DEFILER ( Q , P ) ;
           AFF_STRUCT ( INFO ( P ) , 2 , VRAI ) ;
           ECRIRE ( STRUCT ( INFO ( P ) , 1 ) ) ;
           APPEL Ajouteralafin ( L , STRUCT ( INFO ( P ) , 1 ) ) ;
           SI PERE ( P ) <> NIL
               SI ( FG ( PERE ( P ) ) = NIL )
                   SI FD ( PERE ( P ) ) = NIL
                       ENFILER ( Q , PERE ( P ) ) ;
                      
                   SINON
                       SI ( STRUCT ( INFO ( FD ( PERE ( P ) ) ) , 2 ) = VRAI )
                           ENFILER ( Q , PERE ( P ) ) ;
                          
                       FSI ;
                      
                   FSI ;
                  
               SINON
                   SI STRUCT ( INFO ( FG ( PERE ( P ) ) ) , 2 ) = VRAI
                       SI FD ( PERE ( P ) ) = NIL
                           ENFILER ( Q , PERE ( P ) ) ;
                          
                       SINON
                           SI STRUCT ( INFO ( FD ( PERE ( P ) ) ) , 2 ) = VRAI
                               ENFILER ( Q , PERE ( P ) ) ;
                              
                           FSI ;
                          
                       FSI ;
                      
                   FSI ;
                  
               FSI ;
              
           FSI ;
          
       FTQ ;
       APPEL Resettree ( Root ) ;
      
   FIN
  /********************      Enqueue leaves reverse **********************/
   ACTION Enqueueleavesrev ( Root , Q ) ;
   SOIT
       Root UN ARB DE ( ENTIER , BOOLEEN ) ;
       Q : FILE DE ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI Root <> NIL
           APPEL Enqueueleavesrev ( FD ( Root ) , Q ) ;
           SI ( FD ( Root ) = NIL ) ET ( FG ( Root ) = NIL )
               ENFILER ( Q , Root ) ;
              
           FSI ;
           APPEL Enqueueleavesrev ( FG ( Root ) , Q ) ;
          
       FSI ;
      
   FIN
  /******************       Verify Traversal 4    ****************************/
   FONCTION Verifytraversal4 ( Root , List ) : BOOLEEN
   SOIENT
       Root UN ARB DE ( ENTIER , BOOLEEN ) ;
       Temp UNE FILE DE ARB DE ( ENTIER , BOOLEEN ) ;
       L UNE FILE DE ENTIER ;
       Egaux UN BOOLEEN ;
       A UN ENTIER ;
       List UNE LISTE DE ENTIER ;
       P UN ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       CREERFILE ( L ) ;
       CREERFILE ( Temp ) ;
       Egaux := VRAI ;
       TANTQUE ( STRUCT ( INFO ( Root ) , 2 ) ) = FAUX
           APPEL Enfilerverify4 ( Root , Temp ) ;
          /* Enfile les noeuds consideres comme feuille */
           TANTQUE NON FILEVIDE ( Temp )
               DEFILER ( Temp , P ) ;
               AFF_STRUCT ( INFO ( P ) , 2 , VRAI ) ;
              /* Les mets a visited*/
               ENFILER ( L , STRUCT ( INFO ( P ) , 1 ) ) ;
              
           FTQ ;
          
       FTQ ;
       APPEL Resettree ( Root ) ;
       TANTQUE NON FILEVIDE ( L )
           DEFILER ( L , A ) ;
           SI VALEUR ( List ) <> A
               Egaux := FAUX ;
              
           FSI ;
           List := SUIVANT ( List ) ;
          
       FTQ ;
       Verifytraversal4 := Egaux ;
       APPEL Resettree ( Root ) ;
      
   FIN
  /*************************************/
   ACTION Enfilerverify4 ( Root , L )
   SOIENT
       Root UN ARB DE ( ENTIER , BOOLEEN ) ;
       L UNE FILE DE ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI Root <> NIL
           APPEL Enfilerverify4 ( FD ( Root ) , L ) ;
           SI ( FG ( Root ) = NIL )
               SI FD ( Root ) = NIL
                   SI STRUCT ( INFO ( Root ) , 2 ) = FAUX
                       ENFILER ( L , Root ) ;
                      
                   FSI ;
                  
               SINON
                   SI ( STRUCT ( INFO ( FD ( Root ) ) , 2 ) = VRAI )
                       SI STRUCT ( INFO ( Root ) , 2 ) = FAUX
                           ENFILER ( L , Root ) ;
                          
                       FSI ;
                      
                   FSI ;
                  
               FSI ;
              
           SINON
               SI STRUCT ( INFO ( FG ( Root ) ) , 2 ) = VRAI
                   SI FD ( Root ) = NIL
                       SI STRUCT ( INFO ( Root ) , 2 ) = FAUX
                           ENFILER ( L , Root ) ;
                          
                       FSI ;
                      
                   SINON
                       SI STRUCT ( INFO ( FD ( Root ) ) , 2 ) = VRAI
                           SI STRUCT ( INFO ( Root ) , 2 ) = FAUX
                               ENFILER ( L , Root ) ;
                              
                           FSI ;
                          
                       FSI ;
                      
                   FSI ;
                  
               FSI ;
              
           FSI ;
           APPEL Enfilerverify4 ( FG ( Root ) , L ) ;
          
       FSI ;
      
   FIN
