

//Checks whether two numbers are permutations
function isPermutation(val1,val2) {
    const str1 = String(val1);
    var str2 = String(val2);
    for(const c of str1) {
        if(str2.includes(c)) {
            str2 = str2.replace(c,"");
        }
    }
    return (str2 === "");
}

function eqSet(as, bs) {
    if (as.size !== bs.size) return false;
    for (var a of as) if (!bs.has(a)) return false;
    return true;
}

/* 
Solve: 
*/
const solve = () => {
    var i = 100000;
    var multiples= [2,3,4,5,6];
    while(true) {
        multiples.map(n => {
            return isPermutation(i,n*i);
        })

        if(!isPermutation(i,2*i)) {
            i++;
            continue;
        }
        if(!isPermutation(i,3*i)) {
            i++
            continue;
        }
        if(!isPermutation(i,4*i)) {
            i++
            continue;
        }
        if(!isPermutation(i,5*i)) {
            i++
            continue;
        }
        if(!isPermutation(i,6*i)) {
            i++;
            continue;
        }
        console.log(i);
        document.getElementById("solution").textContent = `Solution: ${i}`;
        return undefined;
    }
}


document.addEventListener("DOMContentLoaded",solve);