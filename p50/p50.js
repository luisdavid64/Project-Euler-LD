

/* Taken From StackOverflow */
const genPrimes = (max) => {
    var sieve  = [], primes = [];
    for (var i = 2; i <= max; ++i) 
    {
        if (!sieve [i]) 
          {
            primes.push(i);
            for (var j = i << 1; j <= max; j += i) 
            {
                sieve[j] = true;
            }
        }
    }
    return primes;
}

/*Generate primes and keep only the 4 digit ones (1000 exclusive)*/
var p = genPrimes(9999).filter(x => x > 1000);

/*Turns every prime into a set of unique digits*/
var setsP = p.map(x =>  {
    var s = [];
    for(const c of x.toString()) {
        s.push(c);
    }
    s.sort();
    return [x,s];
})

/*Group elements based on their sets being equal*/
const group = (list) => {
    map = {};
    list.forEach(element => {
       var key = element[1].join("");
       if(!(key in map)) {
           map[key] = [];
       } 
       map[key].push(element[0]);
    });
    return Object.entries(map);
}

/* 
Solve: 
We want three elements following a sequence, so t1,t2,t3 that follow:
    t2 = t1+n
    t3 = t2+n
    n = t2-t1
    t3 = 2t2 -t1
*/
const solve = () => {
    var groupedP = group(setsP).filter(element => element[1].length >= 3);
    var solution = [];
    groupedP.forEach(element => {
        var arr = element[1].sort();
        for(var i = 2; i < arr.length; i++) {
            if(arr[i] === (2*arr[i-1] - arr[i-2])) {
                solution = [arr[i-2],arr[i-1], arr[i]];
            } 
        }
    })
    var solution = parseInt(solution.join(""));
    var container = document.getElementById("solution");
    container.textContent = `Solution: ${solution}`;
    return solution;
}

document.addEventListener("DOMContentLoaded",solve);