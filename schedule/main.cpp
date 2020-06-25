#include <abc.h>
#include <affair.h>
#include <business.h>
#include <assert.h>
using namespace std;

int main()
{
    Affair One("First", 2, false);
    Affair Two("Second", 1, false);
    Affair Three("Third", 1, true);
    Business List("List", 1, false);

    One.change_complete();
    Two.change_complete();

    List.add_point(&One);
    List.show();
    List.add_point(&Two);
    List.show();
    List.add_point(&Three);
    List.show();

    List.check_complete_all();
    assert(List.get_complete_all() == true);
    cout<<"end.";
}
