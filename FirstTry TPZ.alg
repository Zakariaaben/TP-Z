
   SOIENT
       Monarbre : ARB DE ( ENTIER , ENTIER ) ;
      /****************************            FONCTION ***********************************/
       Verifytreeinorder : FONCTION ( BOOLEEN ) ;
      /* Verifytreeinorder(Root) returns true if bst is created w-o errors*/
      { 
      }
       Search : FONCTION ( BOOLEEN ) ;
      /* Search(Root,value)*/
      { 
      }
      /****************************        Procedure **********************************/
       Inordrepush : ACTION ;
      /* Inordrepush(root,stack); pushed values in order in stack */
      { 
      }
       Afficherarbre : ACTION ;
      /* Afficherarbre(Root) */
      { 
      }
       Inserer : ACTION ;
      /* Inserer(Root,value) */
      { 
      }
       Traversal1 : ACTION ;
      /* Traversal1(Root) */
      { 
      }
       Traversal2 : ACTION ;
      /* Traversal2(Root) */
      { 
      }
       Resettree : ACTION ;
      /* Resettree(Root) sets visited value to 0 */
      { 
      }
       Generatetree : ACTION ;
      /* Generatetree(Root,n) generates a tree with n random unique data */
       Enqueueintraversal2 : ACTION ;
      
   DEBUT
       Monarbre := NIL ;
       APPEL Inserer ( Monarbre , 45 ) ;
       APPEL Inserer ( Monarbre , 20 ) ;
       APPEL Inserer ( Monarbre , 65 ) ;
       APPEL Inserer ( Monarbre , 10 ) ;
       APPEL Inserer ( Monarbre , 35 ) ;
       APPEL Inserer ( Monarbre , 55 ) ;
       APPEL Inserer ( Monarbre , 85 ) ;
       APPEL Inserer ( Monarbre , 50 ) ;
       APPEL Inserer ( Monarbre , 58 ) ;
       APPEL Inserer ( Monarbre , 75 ) ;
       APPEL Inserer ( Monarbre , 95 ) ;
       APPEL Inserer ( Monarbre , 56 ) ;
       APPEL Inserer ( Monarbre , 60 ) ;
       APPEL Inserer ( Monarbre , 90 ) ;
       APPEL Inserer ( Monarbre , 98 ) ;
       APPEL Inserer ( Monarbre , 57 ) ;
       APPEL Inserer ( Monarbre , 62 ) ;
       APPEL Inserer ( Monarbre , 88 ) ;
       APPEL Traversal2 ( Monarbre ) ;
      
   FIN
  { 
   }
  { 
   }
  /****************************      Fonction affichage *************************/
   ACTION Afficherarbre ( R )
   SOIT
       R UN ARB DE ( ENTIER , ENTIER ) ;
      
   DEBUT
       SI R <> NIL
           APPEL Afficherarbre ( FG ( R ) ) ;
           ECRIRE ( STRUCT ( INFO ( R ) , 1 ) ) ;
           APPEL Afficherarbre ( FD ( R ) ) ;
          
       FSI
   FIN
  { 
   }
  /*************************                Verification Creation BST *************************/
   FONCTION Verifytreeinorder ( Root ) : BOOLEEN
   SOIT
       Root UN ARB DE ( ENTIER , ENTIER ) ;
       P UNE PILE DE ( ENTIER , ENTIER ) ;
       A , B DES ( ENTIER , ENTIER ) ;
      
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
  /****************************                Push noeuds Inordre ****************************/
   ACTION Inordrepush ( Root , P )
   SOIT
       Root UN ARB DE ( ENTIER , ENTIER ) ;
       P UNE PILE DE ( ENTIER , ENTIER ) ;
      
   DEBUT
       SI Root <> NIL
           APPEL Inordrepush ( FG ( Root ) , P ) ;
           EMPILER ( P , INFO ( Root ) ) ;
           APPEL Inordrepush ( FD ( Root ) , P ) ;
          
       FSI
   FIN
  { 
   }
  /*************************                Renitialiser Noeuds visités ************************/
   ACTION Resettree ( R )
   SOIT
       R UN ARB DE ( ENTIER , ENTIER ) ;
      
   DEBUT
       SI R <> NIL :
           APPEL Resettree ( FG ( R ) ) ;
           AFF_STRUCT ( INFO ( R ) , 2 , 0 ) ;
           APPEL Resettree ( FD ( R ) ) ;
          
       FSI ;
      
   FIN
  { 
   }
  /*************************                Rechercher noeud dans BST ************************/
   FONCTION Search ( Root , Value ) : BOOLEEN
   SOIT
       Root UN ARB DE ( ENTIER , ENTIER ) ;
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
  /*************************                Inserer Noeud dans BST *************************/
   ACTION Inserer ( Root , Value )
   SOIENT
       Root UN ARB DE ( ENTIER , ENTIER ) ;
       Value UN ENTIER ;
       P UN ARB DE ( ENTIER , ENTIER ) ;
       New UN ( ENTIER , ENTIER ) ;
      
   DEBUT
       SI Root = NIL :
           CREERNOEUD ( Root ) ;
           INIT_STRUCT ( New , [ Value , 0 ] ) ;
           AFF_INFO ( Root , New ) ;
          
       SINON
           SI ( ( Value < STRUCT ( INFO ( Root ) , 1 ) ) ET ( FG ( Root ) = NIL ) ) :
               CREERNOEUD ( P ) ;
               INIT_STRUCT ( New , [ Value , 0 ] ) ;
               AFF_INFO ( P , New ) ;
               AFF_PERE ( P , Root ) ;
               AFF_FG ( Root , P ) ;
              
           SINON
               SI ( ( Value >= STRUCT ( INFO ( Root ) , 1 ) ) ET ( FD ( Root ) = NIL ) ) :
                   CREERNOEUD ( P ) ;
                   INIT_STRUCT ( New , [ Value , 0 ] ) ;
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
  /***********************                Traversal 1 BB-LR-Bottom To Top ***********************/
   ACTION Traversal1 ( Root )
   SOIT
       Root UN ARB DE ( ENTIER , ENTIER ) ;
       Stack UNE PILE DE ARB DE ( ENTIER , ENTIER ) ;
       Q UN ARB DE ( ENTIER , ENTIER ) ;
       A UN ENTIER ;
      
   DEBUT
       Q := Root ;
       SI Q = NIL :
           ECRIRE ( 'L arbre est vide' ) ;
          
       SINON
           TANTQUE ( Q <> NIL )
               SI ( ( FD ( Q ) <> NIL ) ET ( FD ( Q ) <> NIL ) ) :
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
                       SI ( STRUCT ( INFO ( Q ) , 2 ) = 0 )
                           ECRIRE ( STRUCT ( INFO ( Q ) , 1 ) ) ;
                           AFF_STRUCT ( INFO ( Q ) , 2 , 1 ) ;
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
  /***************************               Generer ARBRE BST ***************************/
   ACTION Generatetree ( Root , N )
   SOIT
       Root UN ARB DE ( ENTIER , ENTIER ) ;
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
  /********************      Enqueue Parents of leaves **********************/
   ACTION Enqueueintraversal2 ( Root , Q ) ;
   SOIT
       Root UN ARB DE ( ENTIER , ENTIER ) ;
       Q : FILE DE ARB DE ( ENTIER , ENTIER ) ;
      
   DEBUT
       SI Root <> NIL
           APPEL Enqueueintraversal2 ( FG ( Root ) , Q ) ;
           SI ( FD ( Root ) = NIL ) ET ( FG ( Root ) = NIL )
               AFF_STRUCT ( INFO ( Root ) , 2 , 1 ) ;
               ECRIRE ( STRUCT ( INFO ( Root ) , 1 ) ) ;
               SI PERE ( Root ) <> NIL
                   SI ( FG ( PERE ( Root ) ) = NIL )
                       SI FD ( PERE ( Root ) ) = NIL
                           ENFILER ( Q , PERE ( Root ) ) ;
                          
                       SINON
                           SI ( STRUCT ( INFO ( FD ( PERE ( Root ) ) ) , 2 ) = 1 )
                               ENFILER ( Q , PERE ( Root ) ) ;
                              
                           FSI ;
                          
                       FSI ;
                      
                   SINON
                       SI STRUCT ( INFO ( FG ( PERE ( Root ) ) ) , 2 ) = 1
                           SI FD ( PERE ( Root ) ) = NIL
                               ENFILER ( Q , PERE ( Root ) ) ;
                              
                           SINON
                               SI STRUCT ( INFO ( FD ( PERE ( Root ) ) ) , 2 ) = 1
                                   ENFILER ( Q , PERE ( Root ) ) ;
                                  
                               FSI ;
                              
                           FSI ;
                          
                       FSI ;
                      
                   FSI ;
                  
               FSI ;
              
           FSI ;
           APPEL Enqueueintraversal2 ( FD ( Root ) , Q ) ;
          
       FSI ;
      
   FIN
  /***********************                Traversal 2  ***********************/
   ACTION Traversal2 ( Root )
   SOIT
       Root UN ARB DE ( ENTIER , ENTIER ) ;
       Q UNE FILE DE ARB DE ( ENTIER , ENTIER ) ;
       P UN ARB DE ( ENTIER , ENTIER ) ;
      
   DEBUT
       CREERFILE ( Q ) ;
       APPEL Enqueueintraversal2 ( Root , Q ) ;
       TANTQUE NON FILEVIDE ( Q )
           DEFILER ( Q , P ) ;
           AFF_STRUCT ( INFO ( P ) , 2 , 1 ) ;
           ECRIRE ( STRUCT ( INFO ( P ) , 1 ) ) ;
           SI PERE ( P ) <> NIL
               SI ( FG ( PERE ( P ) ) = NIL )
                   SI FD ( PERE ( P ) ) = NIL
                       ENFILER ( Q , PERE ( P ) ) ;
                      
                   SINON
                       SI ( STRUCT ( INFO ( FD ( PERE ( P ) ) ) , 2 ) = 1 )
                           ENFILER ( Q , PERE ( P ) ) ;
                          
                       FSI ;
                      
                   FSI ;
                  
               SINON
                   SI STRUCT ( INFO ( FG ( PERE ( P ) ) ) , 2 ) = 1
                       SI FD ( PERE ( P ) ) = NIL
                           ENFILER ( Q , PERE ( P ) ) ;
                          
                       SINON
                           SI STRUCT ( INFO ( FD ( PERE ( P ) ) ) , 2 ) = 1
                               ENFILER ( Q , PERE ( P ) ) ;
                              
                           FSI ;
                          
                       FSI ;
                      
                   FSI ;
                  
               FSI ;
              
           FSI ;
          
       FTQ ;
      
   FIN
