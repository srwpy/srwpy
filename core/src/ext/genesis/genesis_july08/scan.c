/* scan.f -- translated by f2c (version 20000118).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

Extern struct {
    doublereal aw0, xkx, xky, wcoefz[3], xlamd, fbess0, delaw, awd, awx, awy, 
	    gamma0, delgam, rxbeam, rybeam, alphax, alphay, emitx, emity, 
	    xbeam, ybeam, pxbeam, pybeam, cuttail, curpeak, conditx, condity, 
	    bunch, bunchphase, emod, emodphase, xlamds, prad0, zrayl, zwaist, 
	    rmax0, zsep, delz, zstop, quadf, quadd, fl, dl, drl, f1st, qfdx, 
	    qfdy, sl, solen, curlen, shotnoise, svar, dgrid, eloss, version, 
	    ibfield, imagl, idril, igamref, pradh0, itram11, itram12, itram13,
	     itram14, itram15, itram16, itram21, itram22, itram23, itram24, 
	    itram25, itram26, itram31, itram32, itram33, itram34, itram35, 
	    itram36, itram41, itram42, itram43, itram44, itram45, itram46, 
	    itram51, itram52, itram53, itram54, itram55, itram56, itram61, 
	    itram62, itram63, itram64, itram65, itram66, rmax0sc;
    integer iseed, nwig, nsec, npart, ncar, lbc, nscr, nscz, nptr, ildgam, 
	    ildpsi, ildx, ildy, ildpx, ildpy, itgaus, nbins, iphsty, ishsty, 
	    ippart, ispart, ipradi, isradi, iertyp, iwityp, idump, iotail, 
	    nharm, iallharm, iharmsc, magin, magout, lout[40], ffspec, ntail, 
	    nslice, iall, itdp, ipseed, iscan, nscan, isntyp, isravg, isrsig, 
	    iorb, ndcut, idmppar, idmpfld, ilog, igamgaus, convharm, 
	    alignradf, offsetradf, multconv, trama, iscrkup, inverfc;
    char beamfile[30], fieldfile[30], maginfile[30], magoutfile[30], 
	    outputfile[30], inputfile[30], scan[30], distfile[30], partfile[
	    30], filetype[30], radfile[30];
} inputcom_;

#define inputcom_1 inputcom_

Extern struct {
    doublereal xkw0, xkper0, sval, svalout, gamma0_in__;
    integer npart0, inorun;
} simcom_;

#define simcom_1 simcom_

Extern struct {
    //doublecomplex crfield[476847], crsource[68121], crmatc[1827], cstep[7], crhm[68121], cwet[1827], cbet[1827];
    doublecomplex *crfield, *crsource, *crmatc, cstep[7], *crhm, *cwet, *cbet;
    doublereal dxy, xks, radphase, besselcoupling[7];
    integer nhloop, hloop[7];
} cartcom_;

#define cartcom_1 cartcom_

Extern struct {
    //doublereal xpart[1000001], ypart[1000001], px[1000001], py[1000001], 
	   // gamma[1000001], theta[1000001], xporb[1000001], yporb[1000001], 
	   // btpar[1000001], btper[1000001], ez[1000001], wx[1000001], wy[
	   // 1000001], xcuren, dedz, tdmin, tdmax, delcharge, dtd, charge;
    //integer lostid[1000001], lost, losttot, ipos[4000004]	/* was [4][1000001] */;
    doublereal *xpart, *ypart, *px, *py, *gamma, 
		*theta, *xporb, *yporb, *btpar, *btper, *ez, *wx, *wy, 
		xcuren, dedz, tdmin, tdmax, delcharge, dtd, charge;
    integer *lostid, lost, losttot, *ipos;
} beamcom_;

#define beamcom_1 beamcom_

Extern struct {
    //doublereal tgam0[50000], tdgam[50000], temitx[50000], temity[50000], 
	   // txrms[50000], tyrms[50000], txpos[50000], typos[50000], tpxpos[
	   // 50000], tpypos[50000], talphx[50000], talphy[50000], tcurrent[
	   // 50000], tpos[50000], tloss[50000], distgam[1250000], distx[
	   // 1250000], disty[1250000], distpx[1250000], distpy[1250000], distt[
	   // 1250000], tradpos[50000], tzrayl[50000], tzwaist[50000], tprad0[
	   // 50000], tradphase[50000];
    doublereal *tgam0, *tdgam, *temitx, *temity, *txrms, *tyrms, *txpos, 
		*typos, *tpxpos, *tpypos, *talphx, *talphy, *tcurrent, *tpos, *tloss, 
		*distgam, *distx, *disty, *distpx, *distpy, *distt, 
		*tradpos, *tzrayl, *tzwaist, *tprad0, *tradphase;
    integer ndata, nsep, nslp, ndist, nraddata;
} tbunchcom_;

#define tbunchcom_1 tbunchcom_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int scaninit_()
{
/*     ============================================================ */
/*     initialize beam parameter for scanning */
/*     ------------------------------------------------------------ */





/*     error codes */

/* genesis version */
/* platform */
/* indicator for original fil */
/* indicator for sdds filetyp */
/* # of particles */
/* # of integration steps */
/* # of slices */
/* maximum of harmonics */
/* maximum of particle in imp */
/* <> 0 keeps distribution in */
/* energy units (mc^2) in ev */
/* vacuum impedence in ohms */
/* speed of light * electron */
/* pi */
/* pi/2 */
/* 2*pi */
/* check i for precission */
/* check ii for precission */
/* number of radial points fo */
/* # of gridpoints of cartesi */


/*     function prototypes */


/*     ------------------------------------------------------ */
/*     all input variables */

/*     wiggler */
/*     electron beam */
/*     radiation */
/*     grid-quantities */
/*     control */
/*     strong focusing */
/*     loading */
/*     output */
/*     external files */
/*     time-dependency */
/*     scan */
/*     extension */
/*     transfermatrix */



/*     simulation control and normalisation parameter */


    if (inputcom_1.iscan <= 0) {
	return 0;
    }

    simcom_1.npart0 = inputcom_1.npart;

    if (inputcom_1.iscan > 22) {
	return 0;
    }

/* scan from beamfile */
    if (inputcom_1.iscan == 1) {
	simcom_1.sval = inputcom_1.gamma0;
    }
/* save original value */
    if (inputcom_1.iscan == 2) {
	simcom_1.sval = inputcom_1.delgam;
    }
    if (inputcom_1.iscan == 3) {
	simcom_1.sval = inputcom_1.curpeak;
    }
    if (inputcom_1.iscan == 4) {
	simcom_1.sval = inputcom_1.xlamds;
    }
/* save original value */
    if (inputcom_1.iscan == 5) {
	simcom_1.sval = inputcom_1.aw0;
    }
    if (inputcom_1.iscan == 6) {
	simcom_1.sval = (doublereal) inputcom_1.iseed;
    }
    if (inputcom_1.iscan == 7) {
	simcom_1.sval = inputcom_1.pxbeam;
    }
    if (inputcom_1.iscan == 8) {
	simcom_1.sval = inputcom_1.pybeam;
    }
    if (inputcom_1.iscan == 9) {
	simcom_1.sval = inputcom_1.xbeam;
    }
    if (inputcom_1.iscan == 10) {
	simcom_1.sval = inputcom_1.ybeam;
    }
    if (inputcom_1.iscan == 11) {
	simcom_1.sval = inputcom_1.rxbeam;
    }
    if (inputcom_1.iscan == 12) {
	simcom_1.sval = inputcom_1.rybeam;
    }
    if (inputcom_1.iscan == 13) {
	simcom_1.sval = inputcom_1.xlamd;
    }
    if (inputcom_1.iscan == 14) {
	simcom_1.sval = inputcom_1.delaw;
    }
    if (inputcom_1.iscan == 15) {
	simcom_1.sval = inputcom_1.alphax;
    }
    if (inputcom_1.iscan == 16) {
	simcom_1.sval = inputcom_1.alphay;
    }
    if (inputcom_1.iscan == 17) {
	simcom_1.sval = inputcom_1.emitx;
    }
    if (inputcom_1.iscan == 18) {
	simcom_1.sval = inputcom_1.emity;
    }
    if (inputcom_1.iscan == 19) {
	simcom_1.sval = inputcom_1.prad0;
    }
    if (inputcom_1.iscan == 20) {
	simcom_1.sval = inputcom_1.zrayl;
    }
    if (inputcom_1.iscan == 21) {
	simcom_1.sval = inputcom_1.zwaist;
    }
    if (inputcom_1.iscan == 22) {
	simcom_1.sval = inputcom_1.awd;
    }

    return 0;
} /* scaninit_ */



/* Subroutine */ int doscan_(islice)
integer *islice;
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer i_dnnt();

    /* Local variables */
    extern /* Subroutine */ int magfield_();
    static doublereal scale;
    extern /* Subroutine */ int getdiag_();
    extern doublereal ran1_();

/*     ========================================================================= */
/*     modify parameter for scanning - several subroutines have to be rerun */
/*     ------------------------------------------------------------------------- */





/*     error codes */

/* genesis version */
/* platform */
/* indicator for original fil */
/* indicator for sdds filetyp */
/* # of particles */
/* # of integration steps */
/* # of slices */
/* maximum of harmonics */
/* maximum of particle in imp */
/* <> 0 keeps distribution in */
/* energy units (mc^2) in ev */
/* vacuum impedence in ohms */
/* speed of light * electron */
/* pi */
/* pi/2 */
/* 2*pi */
/* check i for precission */
/* check ii for precission */
/* number of radial points fo */
/* # of gridpoints of cartesi */


/*     function prototypes */

/*     -------------------------------------------------------------------- */
/*     cartesian mesh */




/*     ------------------------------------------------------ */
/*     all input variables */

/*     wiggler */
/*     electron beam */
/*     radiation */
/*     grid-quantities */
/*     control */
/*     strong focusing */
/*     loading */
/*     output */
/*     external files */
/*     time-dependency */
/*     scan */
/*     extension */
/*     transfermatrix */


/*     ------------------------------------------------------------------ */
/*     electron beam */




/*     simulation control and normalisation parameter */



/*     -------------------------------------------------------------------- */
/*     time dependency of bunch + slippage field */





    if (inputcom_1.iscan <= 0) {
	return 0;
    }
    inputcom_1.npart = simcom_1.npart0;

/* compensate former particle losses */
    if (inputcom_1.iscan > 22) {
/* use data from beamfile for each run of s */
	inputcom_1.gamma0 = tbunchcom_1.tgam0[*islice - 1];
	inputcom_1.delgam = tbunchcom_1.tdgam[*islice - 1];
	inputcom_1.rxbeam = tbunchcom_1.txrms[*islice - 1];
	inputcom_1.rybeam = tbunchcom_1.tyrms[*islice - 1];
	inputcom_1.xbeam = tbunchcom_1.txpos[*islice - 1];
	inputcom_1.ybeam = tbunchcom_1.typos[*islice - 1];
	inputcom_1.emitx = tbunchcom_1.temitx[*islice - 1];
	inputcom_1.emity = tbunchcom_1.temity[*islice - 1];
	inputcom_1.pxbeam = tbunchcom_1.tpxpos[*islice - 1];
	inputcom_1.pybeam = tbunchcom_1.tpypos[*islice - 1];
	inputcom_1.alphax = tbunchcom_1.talphx[*islice - 1];
	inputcom_1.alphay = tbunchcom_1.talphy[*islice - 1];
	beamcom_1.xcuren = tbunchcom_1.tcurrent[*islice - 1];
	beamcom_1.dedz = tbunchcom_1.tloss[*islice - 1] * inputcom_1.delz * 
		inputcom_1.xlamd / 510999.06;
	if (inputcom_1.iscan == 24) {
	    inputcom_1.xlamds = inputcom_1.xlamd * (float).5 * (
		    inputcom_1.aw0 * inputcom_1.aw0 + 1.) / inputcom_1.gamma0 
		    / inputcom_1.gamma0;
	    cartcom_1.xks = 6.28318530717958 / inputcom_1.xlamds;
	    d__1 = inputcom_1.delz * inputcom_1.xlamd;
	    d__2 = cartcom_1.dxy / simcom_1.xkper0;
	    getdiag_(&d__1, &d__2, &cartcom_1.xks);
	}
	if (inputcom_1.iscan == 25) {
	    inputcom_1.gamma0 = simcom_1.gamma0_in__;
	}
	return 0;
    }

    scale = inputcom_1.svar * ((real) (*islice - 1) * (float)2. / (real) (
	    inputcom_1.nslice - 1) - (float)1.) + (float)1.;
    simcom_1.svalout = simcom_1.sval * scale;
/* save for output */
    if (inputcom_1.iscan == 6) {
	simcom_1.svalout = simcom_1.sval + *islice - 1;
    }

/*     beam parameters */

    if (inputcom_1.iscan == 1) {
	inputcom_1.gamma0 = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan == 2) {
	inputcom_1.delgam = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan == 3) {
	beamcom_1.xcuren = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan == 7) {
	inputcom_1.pxbeam = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan == 8) {
	inputcom_1.pybeam = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan == 9) {
	inputcom_1.xbeam = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan == 10) {
	inputcom_1.ybeam = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan == 11) {
	inputcom_1.rxbeam = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan == 12) {
	inputcom_1.rybeam = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan == 15) {
	inputcom_1.alphax = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan == 16) {
	inputcom_1.alphay = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan == 17) {
	inputcom_1.emitx = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan == 18) {
	inputcom_1.emity = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan <= 3) {
	return 0;
    }
    if (inputcom_1.iscan >= 7 && inputcom_1.iscan <= 12) {
	return 0;
    }
    if (inputcom_1.iscan >= 15 && inputcom_1.iscan <= 18) {
	return 0;
    }

/*     radiation parameters */

    if (inputcom_1.iscan == 4) {
	inputcom_1.xlamds = simcom_1.sval * scale;
	cartcom_1.xks = 6.28318530717958 / inputcom_1.xlamds;
	d__1 = inputcom_1.delz * inputcom_1.xlamd;
	d__2 = cartcom_1.dxy / simcom_1.xkper0;
	getdiag_(&d__1, &d__2, &cartcom_1.xks);
    }
    if (inputcom_1.iscan == 19) {
	inputcom_1.prad0 = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan == 20) {
	inputcom_1.zrayl = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan == 21) {
	inputcom_1.zwaist = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan == 22) {
	inputcom_1.awd = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan == 4 || inputcom_1.iscan >= 19) {
	return 0;
    }

/*     magnets parameter */

    if (inputcom_1.iscan == 5) {
	inputcom_1.aw0 = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan == 13) {
	inputcom_1.xlamd = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan == 14) {
	inputcom_1.delaw = simcom_1.sval * scale;
    }
    if (inputcom_1.iscan != 6) {
	i__1 = -i_dnnt(&simcom_1.sval);
	scale = ran1_(&i__1);
    }
/* reinit ran1 function */
    magfield_(&simcom_1.xkw0, &c__1);
/* recalculate magnetic f */
    if (inputcom_1.iscan == 13) {
	d__1 = inputcom_1.delz * inputcom_1.xlamd;
	d__2 = cartcom_1.dxy / simcom_1.xkper0;
	getdiag_(&d__1, &d__2, &cartcom_1.xks);
    }
    return 0;
} /* doscan_ */

