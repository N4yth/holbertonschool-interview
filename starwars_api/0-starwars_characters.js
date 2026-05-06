#!/usr/bin/node

const { argv } = require('process');

async function main() {
  const url = `https://swapi-api.hbtn.io/api/films/${argv[2]}/`;

  const response = await fetch(url);
  const datafilm = await response.json();

  for (const characterUrl of datafilm.characters) {
    const res = await fetch(characterUrl);
    const data = await res.json();
    console.log(data.name);
  }
}

main();
