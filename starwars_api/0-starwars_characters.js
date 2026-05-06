#!/usr/bin/node

const { argv } = require('process');
const url = 'https://swapi-api.hbtn.io/api/films/' + argv[2] + '/'
const request = new Request(url);
var requestcharacter;

fetch(request).then((response) => {
  return response.json();
})
  .then((datafilm) => {
    datafilm.characters.forEach(Characters => {
        requestcharacter = new Request(Characters);
        fetch(requestcharacter).then((response) => {
            return response.json();
            })
            .then((datacharacters) => {
                console.log(datacharacters.name)
            });
    });
});
