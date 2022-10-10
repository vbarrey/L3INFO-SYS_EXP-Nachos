#include "syscall.h"
#ifdef CHANGED

//----------------------------------------------------------------------
// Ce test de l'appel système PutString permet de verifier sont bon fonctionnement en affichant une chaine de caratere dans la console.
// Il suffit de lancer depuis userprog avec la commande ./nachos -x ../test/putstring
// Une fois lancer le programme affcihe la chaine "Hello world!\n".
// La première chaine a une taille inférieure a MAX_STRING_SIZE, la deuxième une atille supérieure.
//----------------------------------------------------------------------

int main()
{
    char *s = "Hello world!\n";
    PutString(s);
    s = "Lorem ipsum dolor sit amet. Aut deleniti corporis ut dignissimos distinctio At nulla libero ut rerum distinctio et veniam expedita et odio provident aut Quis facere! Aut temporibus ipsum non neque fuga et dignissimos vero ea voluptatibus beatae et galisum molestiae sed blanditiis aliquid eos rerum iste. Sit soluta aspernatur a assumenda atque sed eius repellat ut quidem pariatur At incidunt nobis cum fugit atque. Hic blanditiis galisum rem nemo neque 33 dolor consequatur in unde unde et quia tempore et ipsam quasi vel velit ducimus. Quod odio vel doloribus amet sunt ipsam vel aliquid accusamus qui quia saepe. Ut omnis autem vero error non harum soluta? Aut adipisci soluta qui sapiente iste ea placeat debitis id recusandae unde et consequatur doloribus. Sed asperiores dicta ut expedita aliquid et sunt harum. Sed consequatur doloremque est facere mollitia ea quisquam saepe sed officia maiores qui voluptatem rerum id optio velit? Aut rerum nisi ut fugit similique et sint natus est molestiae beatae in molestiae quia ab nihil molestiae. Et quaerat magnam ab assumenda nihil aut saepe omnis est consequatur quaerat. Aut recusandae voluptatem non perferendis obcaecati non quia consequatur aut neque molestiae ad vero rerum. Est commodi earum qui natus earum sed libero voluptas et nobis quibusdam non natus eligendi id facere consequatur eos maiores nobis. Eum numquam tempore qui necessitatibus sunt et odit magni est quam fugiat.\n";
    PutString(s);
    s = "vééééééélo!";
    PutString(s);
    return 0;
}

#endif