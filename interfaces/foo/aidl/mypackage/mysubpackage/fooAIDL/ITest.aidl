// FIXME: license file, or use the -l option to generate the files with the header.

package mypackage.mysubpackage.fooAIDL;

@VintfStability
interface ITest {
    // Adding return type to method instead of out param String res since there is only one return value.
    String getTest();

    // Adding return type to method instead of out param boolean res since there is only one return value.
    boolean setTest(in String param);
}