/* MOCA4.f -- translated by f2c (version 19970805).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#ifdef __cplusplus
extern "C" {
#endif
/* OTB patches: replace "f2c.h" by "otb_6S.h" */
/*#include "f2c.h"*/
#include "otb_6S.h"

/*<       subroutine    moca4(a,inu) >*/
/* Subroutine */ int moca4_(doublereal *a, integer *inu)
{
    /* Initialized data */

    static doublereal acr[2048]	/* was [8][256] */ = { 0.,0.,0.,0.,0.,0.,
	    10180.,10190.,0.,0.,0.,0.,0.,0.,10190.,10200.,0.,0.,0.,0.,0.,0.,
	    10200.,10210.,0.,0.,0.,0.,0.,0.,10210.,10220.,0.,0.,0.,0.,0.,0.,
	    10220.,10230.,0.,0.,0.,0.,0.,0.,10230.,10240.,0.,0.,0.,0.,0.,0.,
	    10240.,10250.,0.,0.,0.,0.,0.,0.,10250.,10260.,0.,0.,0.,0.,0.,0.,
	    10260.,10270.,0.,0.,0.,0.,0.,0.,10270.,10280.,0.,0.,0.,0.,0.,0.,
	    10280.,10290.,0.,0.,0.,0.,0.,0.,10290.,10300.,0.,0.,0.,0.,0.,0.,
	    10300.,10310.,0.,0.,0.,0.,0.,0.,10310.,10320.,0.,0.,0.,0.,0.,0.,
	    10320.,10330.,0.,0.,0.,0.,0.,0.,10330.,10340.,0.,0.,0.,0.,0.,0.,
	    10340.,10350.,0.,0.,0.,0.,0.,0.,10350.,10360.,0.,0.,0.,0.,0.,0.,
	    10360.,10370.,0.,0.,0.,0.,0.,0.,10370.,10380.,0.,0.,0.,0.,0.,0.,
	    10380.,10390.,0.,0.,0.,0.,0.,0.,10390.,10400.,0.,0.,0.,0.,0.,0.,
	    10400.,10410.,0.,0.,0.,0.,0.,0.,10410.,10420.,0.,0.,0.,0.,0.,0.,
	    10420.,10430.,0.,0.,0.,0.,0.,0.,10430.,10440.,0.,0.,0.,0.,0.,0.,
	    10440.,10450.,0.,0.,0.,0.,0.,0.,10450.,10460.,0.,0.,0.,0.,0.,0.,
	    10460.,10470.,0.,0.,0.,0.,0.,0.,10470.,10480.,0.,0.,0.,0.,0.,0.,
	    10480.,10490.,0.,0.,0.,0.,0.,0.,10490.,10500.,0.,0.,0.,0.,0.,0.,
	    10500.,10510.,0.,0.,0.,0.,0.,0.,10510.,10520.,0.,0.,0.,0.,0.,0.,
	    10520.,10530.,0.,0.,0.,0.,0.,0.,10530.,10540.,0.,0.,0.,0.,0.,0.,
	    10540.,10550.,0.,0.,0.,0.,0.,0.,10550.,10560.,0.,0.,0.,0.,0.,0.,
	    10560.,10570.,0.,0.,0.,0.,0.,0.,10570.,10580.,0.,0.,0.,0.,0.,0.,
	    10580.,10590.,0.,0.,0.,0.,0.,0.,10590.,10600.,0.,0.,0.,0.,0.,0.,
	    10600.,10610.,0.,0.,0.,0.,0.,0.,10610.,10620.,0.,0.,0.,0.,0.,0.,
	    10620.,10630.,0.,0.,0.,0.,0.,0.,10630.,10640.,0.,0.,0.,0.,0.,0.,
	    10640.,10650.,0.,0.,0.,0.,0.,0.,10650.,10660.,0.,0.,0.,0.,0.,0.,
	    10660.,10670.,0.,0.,0.,0.,0.,0.,10670.,10680.,0.,0.,0.,0.,0.,0.,
	    10680.,10690.,0.,0.,0.,0.,0.,0.,10690.,10700.,0.,0.,0.,0.,0.,0.,
	    10700.,10710.,0.,0.,0.,0.,0.,0.,10710.,10720.,0.,0.,0.,0.,0.,0.,
	    10720.,10730.,0.,0.,0.,0.,0.,0.,10730.,10740.,0.,0.,0.,0.,0.,0.,
	    10740.,10750.,0.,0.,0.,0.,0.,0.,10750.,10760.,0.,0.,0.,0.,0.,0.,
	    10760.,10770.,0.,0.,0.,0.,0.,0.,10770.,10780.,0.,0.,0.,0.,0.,0.,
	    10780.,10790.,0.,0.,0.,0.,0.,0.,10790.,10800.,0.,0.,0.,0.,0.,0.,
	    10800.,10810.,0.,0.,0.,0.,0.,0.,10810.,10820.,0.,0.,0.,0.,0.,0.,
	    10820.,10830.,0.,0.,0.,0.,0.,0.,10830.,10840.,0.,0.,0.,0.,0.,0.,
	    10840.,10850.,0.,0.,0.,0.,0.,0.,10850.,10860.,0.,0.,0.,0.,0.,0.,
	    10860.,10870.,0.,0.,0.,0.,0.,0.,10870.,10880.,0.,0.,0.,0.,0.,0.,
	    10880.,10890.,0.,0.,0.,0.,0.,0.,10890.,10900.,0.,0.,0.,0.,0.,0.,
	    10900.,10910.,0.,0.,0.,0.,0.,0.,10910.,10920.,0.,0.,0.,0.,0.,0.,
	    10920.,10930.,0.,0.,0.,0.,0.,0.,10930.,10940.,0.,0.,0.,0.,0.,0.,
	    10940.,10950.,0.,0.,0.,0.,0.,0.,10950.,10960.,0.,0.,0.,0.,0.,0.,
	    10960.,10970.,0.,0.,0.,0.,0.,0.,10970.,10980.,0.,0.,0.,0.,0.,0.,
	    10980.,10990.,0.,0.,0.,0.,0.,0.,10990.,1.1e4,0.,0.,0.,0.,0.,0.,
	    1.1e4,11010.,0.,0.,0.,0.,0.,0.,11010.,11020.,0.,0.,0.,0.,0.,0.,
	    11020.,11030.,0.,0.,0.,0.,0.,0.,11030.,11040.,0.,0.,0.,0.,0.,0.,
	    11040.,11050.,0.,0.,0.,0.,0.,0.,11050.,11060.,0.,0.,0.,0.,0.,0.,
	    11060.,11070.,0.,0.,0.,0.,0.,0.,11070.,11080.,0.,0.,0.,0.,0.,0.,
	    11080.,11090.,0.,0.,0.,0.,0.,0.,11090.,11100.,0.,0.,0.,0.,0.,0.,
	    11100.,11110.,0.,0.,0.,0.,0.,0.,11110.,11120.,0.,0.,0.,0.,0.,0.,
	    11120.,11130.,0.,0.,0.,0.,0.,0.,11130.,11140.,0.,0.,0.,0.,0.,0.,
	    11140.,11150.,0.,0.,0.,0.,0.,0.,11150.,11160.,0.,0.,0.,0.,0.,0.,
	    11160.,11170.,0.,0.,0.,0.,0.,0.,11170.,11180.,0.,0.,0.,0.,0.,0.,
	    11180.,11190.,0.,0.,0.,0.,0.,0.,11190.,11200.,0.,0.,0.,0.,0.,0.,
	    11200.,11210.,0.,0.,0.,0.,0.,0.,11210.,11220.,0.,0.,0.,0.,0.,0.,
	    11220.,11230.,0.,0.,0.,0.,0.,0.,11230.,11240.,0.,0.,0.,0.,0.,0.,
	    11240.,11250.,0.,0.,0.,0.,0.,0.,11250.,11260.,0.,0.,0.,0.,0.,0.,
	    11260.,11270.,0.,0.,0.,0.,0.,0.,11270.,11280.,0.,0.,0.,0.,0.,0.,
	    11280.,11290.,0.,0.,0.,0.,0.,0.,11290.,11300.,0.,0.,0.,0.,0.,0.,
	    11300.,11310.,0.,0.,0.,0.,0.,0.,11310.,11320.,0.,0.,0.,0.,0.,0.,
	    11320.,11330.,0.,0.,0.,0.,0.,0.,11330.,11340.,0.,0.,0.,0.,0.,0.,
	    11340.,11350.,0.,0.,0.,0.,0.,0.,11350.,11360.,0.,0.,0.,0.,0.,0.,
	    11360.,11370.,0.,0.,0.,0.,0.,0.,11370.,11380.,0.,0.,0.,0.,0.,0.,
	    11380.,11390.,0.,0.,0.,0.,0.,0.,11390.,11400.,0.,0.,0.,0.,0.,0.,
	    11400.,11410.,0.,0.,0.,0.,0.,0.,11410.,11420.,0.,0.,0.,0.,0.,0.,
	    11420.,11430.,0.,0.,0.,0.,0.,0.,11430.,11440.,0.,0.,0.,0.,0.,0.,
	    11440.,11450.,0.,0.,0.,0.,0.,0.,11450.,11460.,0.,0.,0.,0.,0.,0.,
	    11460.,11470.,0.,0.,0.,0.,0.,0.,11470.,11480.,0.,0.,0.,0.,0.,0.,
	    11480.,11490.,0.,0.,0.,0.,0.,0.,11490.,11500.,0.,0.,0.,0.,0.,0.,
	    11500.,11510.,0.,0.,0.,0.,0.,0.,11510.,11520.,0.,0.,0.,0.,0.,0.,
	    11520.,11530.,0.,0.,0.,0.,0.,0.,11530.,11540.,0.,0.,0.,0.,0.,0.,
	    11540.,11550.,0.,0.,0.,0.,0.,0.,11550.,11560.,0.,0.,0.,0.,0.,0.,
	    11560.,11570.,0.,0.,0.,0.,0.,0.,11570.,11580.,0.,0.,0.,0.,0.,0.,
	    11580.,11590.,0.,0.,0.,0.,0.,0.,11590.,11600.,0.,0.,0.,0.,0.,0.,
	    11600.,11610.,0.,0.,0.,0.,0.,0.,11610.,11620.,0.,0.,0.,0.,0.,0.,
	    11620.,11630.,0.,0.,0.,0.,0.,0.,11630.,11640.,0.,0.,0.,0.,0.,0.,
	    11640.,11650.,0.,0.,0.,0.,0.,0.,11650.,11660.,0.,0.,0.,0.,0.,0.,
	    11660.,11670.,0.,0.,0.,0.,0.,0.,11670.,11680.,0.,0.,0.,0.,0.,0.,
	    11680.,11690.,0.,0.,0.,0.,0.,0.,11690.,11700.,0.,0.,0.,0.,0.,0.,
	    11700.,11710.,0.,0.,0.,0.,0.,0.,11710.,11720.,0.,0.,0.,0.,0.,0.,
	    11720.,11730.,0.,0.,0.,0.,0.,0.,11730.,11740.,0.,0.,0.,0.,0.,0.,
	    11740.,11750.,0.,0.,0.,0.,0.,0.,11750.,11760.,0.,0.,0.,0.,0.,0.,
	    11760.,11770.,0.,0.,0.,0.,0.,0.,11770.,11780.,0.,0.,0.,0.,0.,0.,
	    11780.,11790.,0.,0.,0.,0.,0.,0.,11790.,11800.,0.,0.,0.,0.,0.,0.,
	    11800.,11810.,0.,0.,0.,0.,0.,0.,11810.,11820.,0.,0.,0.,0.,0.,0.,
	    11820.,11830.,0.,0.,0.,0.,0.,0.,11830.,11840.,0.,0.,0.,0.,0.,0.,
	    11840.,11850.,0.,0.,0.,0.,0.,0.,11850.,11860.,0.,0.,0.,0.,0.,0.,
	    11860.,11870.,0.,0.,0.,0.,0.,0.,11870.,11880.,0.,0.,0.,0.,0.,0.,
	    11880.,11890.,0.,0.,0.,0.,0.,0.,11890.,11900.,0.,0.,0.,0.,0.,0.,
	    11900.,11910.,0.,0.,0.,0.,0.,0.,11910.,11920.,0.,0.,0.,0.,0.,0.,
	    11920.,11930.,0.,0.,0.,0.,0.,0.,11930.,11940.,0.,0.,0.,0.,0.,0.,
	    11940.,11950.,0.,0.,0.,0.,0.,0.,11950.,11960.,0.,0.,0.,0.,0.,0.,
	    11960.,11970.,0.,0.,0.,0.,0.,0.,11970.,11980.,0.,0.,0.,0.,0.,0.,
	    11980.,11990.,0.,0.,0.,0.,0.,0.,11990.,1.2e4,0.,0.,0.,0.,0.,0.,
	    1.2e4,12010.,0.,0.,0.,0.,0.,0.,12010.,12020.,0.,0.,0.,0.,0.,0.,
	    12020.,12030.,0.,0.,0.,0.,0.,0.,12030.,12040.,0.,0.,0.,0.,0.,0.,
	    12040.,12050.,0.,0.,0.,0.,0.,0.,12050.,12060.,0.,0.,0.,0.,0.,0.,
	    12060.,12070.,0.,0.,0.,0.,0.,0.,12070.,12080.,0.,0.,0.,0.,0.,0.,
	    12080.,12090.,0.,0.,0.,0.,0.,0.,12090.,12100.,0.,0.,0.,0.,0.,0.,
	    12100.,12110.,0.,0.,0.,0.,0.,0.,12110.,12120.,0.,0.,0.,0.,0.,0.,
	    12120.,12130.,0.,0.,0.,0.,0.,0.,12130.,12140.,0.,0.,0.,0.,0.,0.,
	    12140.,12150.,0.,0.,0.,0.,0.,0.,12150.,12160.,0.,0.,0.,0.,0.,0.,
	    12160.,12170.,0.,0.,0.,0.,0.,0.,12170.,12180.,0.,0.,0.,0.,0.,0.,
	    12180.,12190.,0.,0.,0.,0.,0.,0.,12190.,12200.,0.,0.,0.,0.,0.,0.,
	    12200.,12210.,0.,0.,0.,0.,0.,0.,12210.,12220.,0.,0.,0.,0.,0.,0.,
	    12220.,12230.,0.,0.,0.,0.,0.,0.,12230.,12240.,0.,0.,0.,0.,0.,0.,
	    12240.,12250.,0.,0.,0.,0.,0.,0.,12250.,12260.,0.,0.,0.,0.,0.,0.,
	    12260.,12270.,0.,0.,0.,0.,0.,0.,12270.,12280.,0.,0.,0.,0.,0.,0.,
	    12280.,12290.,0.,0.,0.,0.,0.,0.,12290.,12300.,0.,0.,0.,0.,0.,0.,
	    12300.,12310.,0.,0.,0.,0.,0.,0.,12310.,12320.,0.,0.,0.,0.,0.,0.,
	    12320.,12330.,0.,0.,0.,0.,0.,0.,12330.,12340.,0.,0.,0.,0.,0.,0.,
	    12340.,12350.,0.,0.,0.,0.,0.,0.,12350.,12360.,0.,0.,0.,0.,0.,0.,
	    12360.,12370.,0.,0.,0.,0.,0.,0.,12370.,12380.,0.,0.,0.,0.,0.,0.,
	    12380.,12390.,0.,0.,0.,0.,0.,0.,12390.,12400.,0.,0.,0.,0.,0.,0.,
	    12400.,12410.,0.,0.,0.,0.,0.,0.,12410.,12420.,0.,0.,0.,0.,0.,0.,
	    12420.,12430.,0.,0.,0.,0.,0.,0.,12430.,12440.,0.,0.,0.,0.,0.,0.,
	    12440.,12450.,0.,0.,0.,0.,0.,0.,12450.,12460.,0.,0.,0.,0.,0.,0.,
	    12460.,12470.,0.,0.,0.,0.,0.,0.,12470.,12480.,0.,0.,0.,0.,0.,0.,
	    12480.,12490.,0.,0.,0.,0.,0.,0.,12490.,12500.,0.,0.,0.,0.,0.,0.,
	    12500.,12510.,0.,0.,0.,0.,0.,0.,12510.,12520.,0.,0.,0.,0.,0.,0.,
	    12520.,12530.,0.,0.,0.,0.,0.,0.,12530.,12540.,0.,0.,0.,0.,0.,0.,
	    12540.,12550.,0.,0.,0.,0.,0.,0.,12550.,12560.,0.,0.,0.,0.,0.,0.,
	    12560.,12570.,0.,0.,0.,0.,0.,0.,12570.,12580.,0.,0.,0.,0.,0.,0.,
	    12580.,12590.,0.,0.,0.,0.,0.,0.,12590.,12600.,0.,0.,0.,0.,0.,0.,
	    12600.,12610.,0.,0.,0.,0.,0.,0.,12610.,12620.,0.,0.,0.,0.,0.,0.,
	    12620.,12630.,0.,0.,0.,0.,0.,0.,12630.,12640.,0.,0.,0.,0.,0.,0.,
	    12640.,12650.,0.,0.,0.,0.,0.,0.,12650.,12660.,0.,0.,0.,0.,0.,0.,
	    12660.,12670.,0.,0.,0.,0.,0.,0.,12670.,12680.,0.,0.,0.,0.,0.,0.,
	    12680.,12690.,0.,0.,0.,0.,0.,0.,12690.,12700.,0.,0.,0.,0.,0.,0.,
	    12700.,12710.,0.,0.,0.,0.,0.,0.,12710.,12720.,0.,0.,0.,0.,0.,0.,
	    12720.,12730.,0.,0.,0.,0.,0.,0.,12730.,12740. };

    integer i__;

/*<        real a(8) >*/
/*<        real acr(8,256) >*/
/*<        integer inu,j,k,i >*/
/*     carbon monoxide (10180 - 12730 cm-1) */

/*<    >*/
    /* Parameter adjustments */
    --a;

    /* Function Body */
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/

/*<       do i=1,8 >*/
    for (i__ = 1; i__ <= 8; ++i__) {
/*<       a(i)=acr(i,inu) >*/
	a[i__] = acr[i__ + (*inu << 3) - 9];
/*<       enddo >*/
    }

/*<       return >*/
    return 0;
/*<       end >*/
} /* moca4_ */

#ifdef __cplusplus
	}
#endif