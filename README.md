# Esercitazione sull'overload degli operatori
Un numero complesso è un numero della forma $z = a+ib$, dove $i = sqrt(-1)$
è l'unità immaginaria. I due numeri reali $a$ e $b$ sono detti rispettivamente
_parte reale_ e _parte immaginaria_.

Si definisca una classe template **complex number** che modella i numeri
complessi. La classe template prende come parametro il tipo **T** con il quale si
rappresentano $a$ e $b$ sulla macchina. La classe deve funzionare correttamente
per `T = float` e `T = double`.
Tale classe template deve:

* Avere un costruttore di default
* Avere un costruttore user-defined per l'inizializzaione di parte reale e immaginaria
* Fornire un overload dell'operatore `<<` per stampare il numero complesso. Se per esempio $a=1$ e $b=2$, dev'essere stampato $1+2i$, mentre $b=-2$ dev'essere stampato $1-2i$.
* Fornire un overload degli operatori `+=` e `+`.
* Fornire un overload degli operatori `*=` e `*`.
* Opzionale: in modo simile a quanto fatto in classe nel caso di **rational**, utilizzare i _concept_ per vincolare T ad essere un tipo floating point.
